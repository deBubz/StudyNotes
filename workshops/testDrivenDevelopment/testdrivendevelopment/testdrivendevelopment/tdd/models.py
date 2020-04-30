from django.db import models
from django.contrib.auth.models import User, Group

# Create your models here.
class Post(models.Model):
    users = models.ForeignKey(User, on_delete=models.CASCADE)
    group = models.ForeignKey(Group, related_name="group", on_delete=models.CASCADE)

    def __repr__(self):
        return "{group} with {users}".format(self.group, self.users)
    