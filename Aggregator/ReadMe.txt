//////////////////////////////////////////////////////////////////////////////////////////////////
// Aggregator- A web feed parser
// Master's Project, MS CE
// Developed By: Kunal Kantawala
// SUID: 291269034
// Contact: 201.707.4446
// Email: kpkantaw@syr.edu
// Programming Language Used: ObjectiveC
// Tools: Xcode, available at http://developer.apple.com/technologies/tools/xcode.html
// Operating System: iOS 4.1
// Date: 12/20/2010  
////////////////////////////////////////////////////////////////////////////////////////////////////

System Configurations Used During Development of The Application:

1. Mac OS X Version 10.6.4 (Processor 2.16 GHz Intel Core Duo, Memory 2 GB 667 MHz DDR2 SDRAM )
2. Xcode Version 3.2.4(1708) 
3. iPhone OS 4.1    

Make sure you have Xcode installed on your Mac OS X.
Xcode is available for free download at http://developer.apple.com/technologies/tools/xcode.html

Open the project folder.

Double click on Aggregator.xcodeproj file.

Xcode should open the project in its explorer.

Make sure simulator is selected before running or building the application.

Make sure in simulator iOS version 4.1 or above is selected, although the application will work fine for all iOS version 3.0 or above.

Now click "Build and Run" button. (if you can not find this button, in top, from tool bar, select Run)

If xcode gives some error, try this:

Right click on Aggregator.xcodeproj
Select "Show Package Contents".
Select project.pbxproject
Double click to open it.
Press Cmd+f
Write "XCBuildConfiguration"
In that look for SDKROOT = iphoneos_._; Here make sure it is 4.1

And try again through above steps.

Problems/Feature Suggestions/Questions/Reviews are welcomed.

