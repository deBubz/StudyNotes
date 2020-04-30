from django.test import TestCase # uses unittests framework in-built with Python
from django.contrib.auth.models import User, Group
from django.db.models import Count

# for testing the API itself
from rest_framework.test import APITestCase
from rest_framework.authtoken.models import Token
from django.urls import reverse

class PostUserAPIModelViewSet(APITestCase):
	def setUp(self):
		# Start with some setup
		# we should begin with no users...
		self.assertEquals(
			User.objects.count(),
			0
		)
		# get the users endpoint
		# url = "http://127.0.0.1:8000/users/"
		self.url = reverse("users-list")

		self.data = {
			"username" : "john",
			"email": "john@test.com",
			"groups": [],
		}

		self.username = 'test'
		self.password = 'nadda'
		self.email = "myemail@test.com"

		self.user = User.objects.create_user(
			self.username, self.password, self.email
		)

		# we won't worry about authentication (it's automatic)
		self.client.force_authenticate(
			user = self.user
		)

		self.assertEquals(
			User.objects.count(),
			1
		)

	def testPOSTUser(self):
		# self has a reference to the API Client object instance, allows us to POST
		# create and send the POST
		response = self.client.get(self.url)

		# assert we can access the /users/ endpoint
		self.assertEquals(
			response.status_code,
			200
		)

		# Now run some real tests
		# now attempt to post some real data, we should get a 201 success
		response = self.client.post(self.url, self.data)
		self.assertEquals(
			response.status_code, 
			201
		)
		# and test that it saved the new user to the db (we had one already in setup)
		self.assertEquals(
			User.objects.count(),
			2
		)

		# we made a data dict, compare it to manually added user (username="test")
		self.assertEquals(
			User.objects.first().username,
			self.username
		)

class GroupViewSet(APITestCase):
	def setUp(self):
		# no groups yet
		self.assertEquals(
			Group.objects.count(),
			0
		)

		# test user to force authentication
		self.username = 'test'
		self.password = 'nadda'
		self.email = "myemail@test.com"

		self.user = User.objects.create_user(
			self.username, self.password, self.email
		)

		# get the groups endpoint
		# url = "http://127.0.0.1:8000/groups/"
		self.url = reverse("groups-list")
		
		self.group = "new group"
		self.data = {
			'name': self.group
		}

		self.manualTestName = "other group"

		Group.objects.create(
			name = self.manualTestName
		)

		# we won't worry about authentication (it's automatic), skip it!
		self.client.force_authenticate(
			user = self.user
		)

		# make sure we can manually add the group!
		self.assertEquals(
			Group.objects.count(),
			1
		)

	def testGroupSearchEndpoint(self):
		# self has a reference to the API Client object instance, allows us to POST
		# create and send the POST
		response = self.client.get(self.url)

		# assert we can access the /groups/ endpoint
		self.assertEquals(
			response.status_code,
			200
		)

		# TODO: Try and write a test for a POST request to the /groups/ endpoint!

		# Now run some real tests
		# 1. Create a response variable based on our POST() to our url with our test data (self.data and self.url)
		# response = ...
		# 2. assert that response.status_code == 201. Tip! Use the assertEquals function!
		# assert statement here...

class WhichGroups(APITestCase):
	def setUp(self):
		# Use the test user to force authentication
		self.username = 'test'
		self.password = 'nadda'
		self.email = "myemail@test.com"

		self.user = User.objects.create_user(
			self.username, self.password, self.email
		)

		# get the whichgroups endpoint
		# url = "http://127.0.0.1:8000/groups/"
		self.url = reverse("custom-list")
		
		self.group = "new group"
		self.data = {
			'name': self.group
		}

		self.manualTestName = "other group"

		self.obj_Group = Group.objects.create(
			name = self.manualTestName
		)

		self.obj_Group.user_set.add(self.user)

		# we won't worry about authentication (it's automatic), skip it!
		self.client.force_authenticate(
			user = self.user
		)

	def testGETWhichGroups(self):
		# self has a reference to the API Client object instance, allows us to POST
		# create and send the POST
		response = self.client.get(self.url)

		# assert we can access the /whichgroups/ endpoint
		self.assertEquals(
			response.status_code,
			200
		)

		response = self.client.get(self.url + "?=" + self.group)
		# our group values are in a nested OrderedDict containing a list and then another OrderedDict
		groups = response.data['results'][0]['groups']
		
		# first check the data actually returned some groups!!
		self.assertNotEquals(
			len(groups),
			0
		)
		# now assert the data returns a list with all correct groups
		for group in groups:
			self.assertEquals(
				group,
				# our returned data is the pk for the group, not its name
				self.obj_Group.pk
			)
		