from django.contrib.auth.models import User, Group
from rest_framework import serializers
from .models import Post

class UserSerializer(serializers.ModelSerializer):
    """
    Adds a serializer interface for the User model with appropriate fields.
    """
    class Meta:
        model = User
        fields = ['username', 'email', 'groups']

class GroupSerializer(serializers.ModelSerializer):
    """
    Adds a serializer interface for the Groups model with appropriate fields.
    """
    class Meta:
        model = Group
        fields = ['name']
