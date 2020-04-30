import os
import sys

def setup_deps():
    if os.system("pip3 install virtualenv"):
        print("Couldn't install virtualenv, do you have pip installed and running this as admin?")
        return
    else:
        print("################\nInstalled virtualenv!!")
    
    if os.system("virtualenv ."):
        print("Couldn't initiate a virtualenvironment...")
        return
    else:
        print("################\nInitiated virtual environment")
        
    if sys.platform == "win32":
        os.system("Scripts\activate")
    elif sys.platform == "darwin" or sys.platform == "linux":
        os.system("source Scripts/activate")
    else:
        print("Couldn't determine the OS to run installation of dependencies.")
        return

    os.system("pip3 install -r requirements")

setup_deps()
