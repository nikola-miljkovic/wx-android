# ascii_nikola
# make-jni for win|nix
# made for wxWidgets
from sys import platform as _platform
import os

if _platform == "win32":
    bash = input('Get bash location: ')
    
proj = input('Get project location: ')
ndk = input('Get ndk-build location, normaly /android-ndk-r9d/:')

os.system('{} --login -c "cd {} && {}"'.format(bash, proj, ndk))