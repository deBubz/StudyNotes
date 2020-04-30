from django.contrib.auth.models import User, Group
from rest_framework import viewsets, permissions, generics
from rest_framework.response import Response
from .serializers import UserSerializer, GroupSerializer
from django.shortcuts import get_object_or_404

from itertools import chain

# Create your views here.
class UserViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows users to be viewed or edited.
    """
    queryset = User.objects.all().order_by('-date_joined')
    serializer_class = UserSerializer
    permission_classes = [permissions.IsAuthenticated]

class GroupViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows groups to be viewed or edited.
    """
    queryset = Group.objects.all()
    serializer_class = GroupSerializer
    permission_classes = [permissions.IsAuthenticated]

# ADDED THIS FOR BUILDING TUTORIAL
class UserinGroupViewSet(viewsets.ModelViewSet):
    """
    API endpoint allowing grouping of users by their groups.
    """

    serializer_class = UserSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        """
        Override the default queryset method.
        Return users in group specified by user.
        """

        queryset = User.objects.all()
        group = self.request.query_params.get('group', None)

        if group is not None:
            queryset = queryset.filter(groups__name=group)
            return queryset 
        else:
            # Default, return the whole queryset. 
            # We could easily set the defualt to show UTS ProgSoc memebers
            #  with pk=1 (groups__name=UTS ProgSoc or groups=1)
            
            # queryset = queryset.filter(groups=1)
            return queryset

