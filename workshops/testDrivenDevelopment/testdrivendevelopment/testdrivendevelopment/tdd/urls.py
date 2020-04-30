from django.urls import include, path
from rest_framework import routers
from . import views

# Instantiate our API router
router = routers.DefaultRouter()

# We have two demo API endpoints, /users and /groups
# These are GET and POST requests (isn't that nice?) that return either all users or groups
router.register(r'users', views.UserViewSet, basename="users")
router.register(r'groups', views.GroupViewSet, basename="groups")

# ADDED THIS FOR TUTORIAL WHERE WE ADD ANOTHER CUSTOM ENDPOINT
# We may replace /users with this endpoint if we like, renaming this users and commenting out the original
router.register(r'whichgroups', views.UserinGroupViewSet, basename="custom")

urlpatterns = [
    path('', include(router.urls)),
]
