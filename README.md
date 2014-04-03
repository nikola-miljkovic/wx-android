wx-android about
==========

wxWidgets port for Android.
This is early development version, it doesn't contain actually usable code.

Development is done on Android 4.2.2 Emulator and SGS II on kitkat 4.4.


I have only used and made(compiled) this code for following build(my own):

Windows 7 x64

Cygwin64

Ndk-revision9

eclipse

Python 2.7



This project so far should work with Linux even tho i didn't test it.

Use make-jni.py especially on windows.

BUILD GUIDE
==========

Run make-jni.py or simply make with terminal. Copy newly made ../libs/ to your project/jni/lib, add include files and use makefiles from sample project.

F.A.Q.
==========


* I want to use my existing wxWidgets code written for other platform on android, does this project make this possible?

  Current version doesn't actually make any connections with existing wxWidgets projects, plan is to one day fully support   all wxWidgets code. I will update this file if this changes.

* What is point of this project?
  
  For now it is just support for idea of wxWidgets port for Android, little proof of concept and helper for making right design ideas.
  Phylosophy is to make good base for C++ and wxWidgets developers to start Android development easy and in enviorment they are used to.

* Who develops and how can i help this project?
  
  I Nikola am leading project atm, however if u are interested in helping you can fork and pull and do what ever you wish.

* Who can use code written in this project?
  
  Anyone, i dont care how this code is used, u can however credit me as it can help me but i dont expect you to do so.
