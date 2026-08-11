from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.shortcuts import reverse
from django import forms

# Create your views here.

class NewTaskForm(forms.Form):
    task = forms.CharField(label="New Task")
    priority = forms.IntegerField(label="Priority", min_value=1)

def index(request):
    if "tasks" not in request.session:
        request.session["tasks"] = []
    return render(request, "tasks/index.html", {
        "tasks": request.session["tasks"]
    })

def add(request):
    # if client is trying to submit data
    if request.method == "POST":
        form = NewTaskForm(request.POST)
        if forms.is_valid(): # if valid save that data 
            task = form.cleaned_data["task"]
            request.session["task"] += [task]
            return HttpResponseRedirect(reverse("tasks:index"))
        else: # else just render the page, but send back the invalid data so that the client can see an error message
            return render(request, "tasks/add.html", {
                "form": form
            })
    # else just render the page
    return render(request, "tasks/add.html", {
        "form": NewTaskForm()
    })

