# GeoCode Applicatio with Qt

A cross platform application developed with Qt and C++ for finding the location with google map

## Introduction
In this documentation, a description of the app developed for the cross platform development with C++ using Qt will be given. This app is named as “GeoCode” and it display a google map and can find location with location name or coordinates. All the necessary details of this application are given below. It has been checked for cross platform compatibility also.

## Technical Specification

### GUI Design

![image](https://github.com/UdaraBGAkila/GeoCodeQt/assets/22652266/3f1140ca-ed2d-42c3-ab7f-852c546dda26)

The applications GUI looks as above picture. On the top left corner there are 2 buttons and with “Geocode” button clicked, you can enter the location name and with “Reverse Geocode” button clicked, you can enter longitude and latitude and get the location on the below map by clicking on find.
In the center area of the application a goggle map is displayed and it is used to show the location returns from above operations.
In the bottom left of the application there are 2 buttons to zoom in and zoom out current loaded map. In the bottom left with 4 buttons “Up, Down, Left, Right” can be used to move the map in those directions. Home button gets map to the first position of the map.

### Code Documentation

In this application, I have developed it as a QWidget and it includes QWebEngineView as the main component as it shows a google map. As 3rd party libraries I have used google map api to render a google map with necessary javascript functions. There are only main class and widget class in this application. Also 3 html files are used to deliver javascript functions which uses google map api.

#### Widget class

![image](https://github.com/UdaraBGAkila/GeoCodeQt/assets/22652266/18fa291e-4e95-41a6-b80c-35659a1b002e)

With above code a google map is loaded to the QWebEngineView inside the widget ui which created by promoting a QWidget to a QWebEngineView.
For geocode and reverse geocode separate html files with javascript was as mapgeocode.html and mapreversegeocode.html.

![image](https://github.com/UdaraBGAkila/GeoCodeQt/assets/22652266/120df7e1-a3ce-4d23-962b-2c811048563b)

Above code is used for creating functions to zoom and move the loaded google map which is used in button functions.
