from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.urls import reverse
from django import forms

from . import util

import markdown2
import random

class NewEntryForm(forms.Form):
    title = forms.CharField(label="Title")
    content = forms.CharField(widget=forms.Textarea, label="Content")

class EditEntryForm(forms.Form):
    content = forms.CharField(widget=forms.Textarea, label="Content")   

def index(request):
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

# function that renders pages
def entry (request, title):
    content = util.get_entry(title)
    if content is None:
        return render(request, "encyclopedia/error.html", {
            "title": title
        }, status=404)
    return render(request, "encyclopedia/entry.html", {
        "title": title,
        "content": markdown2.markdown(content)
    })

def search(request):
    query = request.GET.get("q", "").strip()
    entries = util.list_entries()

    # exact match
    for entry_name in entries:
        if entry_name.lower() == query.lower():
            return HttpResponseRedirect(reverse("encyclopedia:entry", args=[entry_name]))

    # similar results / search page 
    results = [e for e in entries if query.lower() in e.lower()]
    return render(request, "encyclopedia/search.html", {
        "query": query,
        "results": results
    })

def new_page(request):
    if request.method == "POST":
        form = NewEntryForm(request.POST)
        if form.is_valid():
            title = form.cleaned_data["title"]
            content = form.cleaned_data["content"]

            if util.get_entry(title) is not None:
                return render(request, "encyclopedia/new_page.html", {
                    "form": form,
                    "error": f"An entry with the title {title} already exists."
                })

            util.save_entry(title, content)
            return HttpResponseRedirect(reverse("encyclopedia:entry", args=[title]))
        
        return render(request, "encyclopedia/new_page.html", {"form": form})
    
    return render(request, "encyclopedia/new_page.html", {"form": NewEntryForm()})

def random_page(request):
    entries = util.list_entries()
    entry_name = random.choice(entries)
    return HttpResponseRedirect(reverse("encyclopedia:entry", args=[entry_name]))

def edit_page(request, title):
    content = util.get_entry(title)
    if content is None:
        return render(request, "encyclopedia/error.html", {"title": title}, status=404)
    if request.method == "POST":
        form = EditEntryForm(request.POST)
        if form.is_valid():
            new_content = form.cleaned_data["content"]
            util.save_entry(title, new_content)
            return HttpResponseRedirect(reverse("encyclopedia:entry", args=[title]))
        return render(request, "encyclopedia/edit_page.html", {"title": title, "form": form})
    form = EditEntryForm(initial={"content": content})
    return render(request, "encyclopedia/edit_page.html", {"title": title, "form": form})
    