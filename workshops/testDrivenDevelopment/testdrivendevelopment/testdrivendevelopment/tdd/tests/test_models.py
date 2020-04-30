from django.test import TestCase # uses unittests framework in-built with Python
from django.contrib.auth.models import User, Group
from django.db.models import Count

# for testing the API itself
from rest_framework.test import APITestCase
from rest_framework.views import status
from django.urls import reverse

##########################
# NOTE: All of these tests create a dummy db!! No values you add normally are compared here!!
##########################

# test the User model
class modelsTests(TestCase):
    def testUserModel(self):
        # we should begin with no users...
        self.assertEquals(
            User.objects.count(),
            0
        )
        # create a test group
        Group.objects.create(name="Test")
        # create some demo users, 2 exactly...
        user = User.objects.create_user(username="test user", email="test@unittest.com")
        User.objects.create(username="another user", email="anothertest@unittest.com")

        # test they were created and saved....
        self.assertEquals(
            User.objects.count(),
            2
        )

        self.assertEquals(
        	list(User.objects.filter(username="test user").values("username"))[0]['username'],
        	user.username
        )

    def testGroupModel(self):
        # TODO: Write a simple Group endpoint test!!
        # This endpoint should return data from the Group model
        # test making a new group and some filtering...
        # Pretty cut and paste from above
        pass
