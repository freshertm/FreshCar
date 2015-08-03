FreshCar
========

Small UI application written in C++/Qt my own clone of GeneticCars. 
Based on source from this link: http://habrahabr.ru/post/185882/ (I took some algorithms from here.)

Features:
 - Smart car body creation algorithm.
 - Runtime tuning all of settings. (except settings which affects to genome length).

Issues:
 - Slow. If you use default settings and set population > 50 then fps will be slow. (Depends from machine CPU and number of triangles on scene).
 - Not so good sex() method. I don't find better algorithm for cars reproduction.
 
 
Build application:
 - You may use Qt 4.7 or 4.8 version for build. 
 - This application is builds as regular Qt .pro based app. qmake, make (or nmake if you use Visual Studio to build).
 
Run application.
 - There is settings.ini file in doc folder. It includes some tuned params for better work. But you can run app without it. 
 - This file will create or updated when you close app.
 
