# Installation
1. Run a new command window (Command prompt on windows or Terminal on Linux/MacOS) as __admin/root.__
2. Change directory (cd command) to a location where you want to save this project (a GitHub folder in documents is reccomended)
3. Copy the project from GitHub to your new folder ("some directory"/GitHub) and run `git clone https://github.com/utsprogsoc/testdrivendevelopment.git`
* Optional: Install the (GUI for GitHub)[https://desktop.github.com/] and skip the above step. Avoids installing Git for cmd line.
4. Attempt to run the setup script, `python3 setup.py`
5. If this throws any errors or returns early, let the presenter know so they can help finish the install!
* If you are more familiar, setup is simply creating a virtualenv in the current dir then activating.
* Simply pip3 install -r requirements in an activated environment to complete the setup!!
6. If the script worked for you, setup is complete!! We can now start!!

If the installation worked correctly, the project structure looks like,
```
│   .gitignore
│   LICENSE
│   README.md
│   requirements
│   setup.py
│
└───testdrivendevelopment
    │   db.sqlite3
    │   manage.py
    │
    ├───tdd
    │   │   admin.py
    │   │   apps.py
    │   │   models.py
    │   │   serializers.py
    │   │   urls.py
    │   │   views.py
    │   │   __init__.py
    │   │
    │   ├───migrations
    │   │   │   0001_initial.py
    │   │   │   __init__.py
    │   │
    │   └───tests
    │       │   test_models.py
    │       │   test_views.py
    │       │   __init__.py
    │
    └───testdrivendevelopment
        │   asgi.py
        │   settings.py
        │   urls.py
        │   wsgi.py
        │   __init__.py
```

Your cmd prompt should also now look something like:
`(TDDWOR~1) C:\Users\"your username"\GitHub\testdrivendevelopment >`
The __(TDDWOR~1)__ element indicates we have a virtual environment for installing dependencies, if you don't see this then it needs activating to run the workshop!!

## OS X and GNU-Linux-Whatever-You-Want-To-Call-Linux-These-Days
`source Scripts\bin\activate`

## Windows
`Scripts\activate`

## Double check the installation
We can double check that the required dependencies are installed as well...

* Run `python3 -m pip list` and check the output is the following...
```
Package             Version
------------------- -------
asgiref             3.2.7
Django              3.0.5
django-extensions   2.2.9
djangorestframework 3.11.0
pip                 20.0.2
pytz                2019.3
setuptools          46.1.3
six                 1.14.0
sqlparse            0.3.1
wheel               0.34.2
```

# Test Driven Development Workshop Demo
See below for the idea on what this is and how to run the demo!! Don't worry,
we'll run through this together in the workshop, :D.

Note: the site runs off the default sqlite3 shipped with Django.

## IDEA: 
To begin with as a demo, we have two simple User and Groups API routing setup.
- Each API endpoint exposes a viewset for a model, User or Groups
- calling the site root + model_in_lower_case returns a GET view (but I was nice and added POST too for viz)
..- a POST option is shown below to add new entries
- We will develop a new feature, looking up and returning all users in a given group!
- This will be done with the test driven development method

## Using the demo (NOTE: use python or python3 as needed, depends on your install)
1. cd to the project directory testdrivendevelopment
2. run python3 manage.py createsuperuser,
3. Now enter admin as the username and the password as tdd123 (hit enter over the
email and type y to override the password feature)
4. run python3 manage.py runserver 
5. open the indicated link for the base URL (http://localhost:8000 by default) 
6. Login with the top right corner, admin w/ tdd123. Now the application will accept you!!
7. Browse our two endpoints!!

## Running a test
1. cd to the project directory, this will contain the script `mange.py`
2. run python3 manage.py test
3. Check the outputs!! This would've created the setup for the tests, a new empty database, run the tests and torn the whole thing down for you!
