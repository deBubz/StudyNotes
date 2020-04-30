"""
testdrivendevelopment URL Configuration
"""
from django.urls import include, path
from rest_framework import routers

from django.contrib import admin
from django.urls import path

# Connect up the API using automatic URL routing that's built-in with Django
# Also, include login URLs for the browsable API.
urlpatterns = [
    path('api-auth/', include('rest_framework.urls', namespace='rest_framework')),
    path('admin/', admin.site.urls),
    path('', include('tdd.urls'))
]
