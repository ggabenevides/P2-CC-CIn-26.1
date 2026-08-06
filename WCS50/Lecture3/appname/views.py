from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def index(request):
    return render(request, "appname/index.html")

def gabi(request):
    return HttpResponse("Hello, gabi")

def greet(request, name):
    return render(request, "appname/greet.html", {
        "name": name.capitalize()
    })
