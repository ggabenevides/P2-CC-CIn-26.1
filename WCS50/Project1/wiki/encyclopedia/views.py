from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.urls import reverse

from . import util

import markdown2

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

# exact match
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
    