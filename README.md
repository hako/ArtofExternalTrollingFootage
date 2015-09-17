#The Art of External Trolling: The Footage#

![My image](http://www.hakobaito.co.uk/wp-content/uploads/2011/11/dscard_1.png)


**The Art of External Trolling: The Footage**, is a Nintendo DS extension to the animation _[The Art of External Trolling.](http://youtu.be/PvsUVSAKUv8)_
This is a personal experiment exploring the idea of adding software to my animations.

So that not only you watch the cartoon, but you also play additional content related to the cartoon, However, this requires you to watch the cartoon before hand before you even play it.


Synopsis
-

> **Harold Foltz** and his business has been blown to pieces all because he got trolled
by a ROM he inserted into a VDR. His aide gave him a ROM which came from an unknown source.
After this catastrophe happened, he quickly retrieved the remains of the VDR alongside the ROM
contained inside of it. The ROM was badly damaged, but the contents were recovered and encoded by researchers.
Since the ROM was in an unrecognisable format, a clue suggests that only a Nintendo DS is able to play it.

> **THIS IS WHERE YOU WATCH THE FOOTAGE**.

Compiling
-

You need the following to compile the footage that Mr Foltz has given you.

+ **DevkitPro** - The SDK for DS homebrew.
+ **libnds** - The core DS homebrew library.
+ <del>**nflib** - An additional DS library for libnds</del> [(included)](https://github.com/hako/ArtofExternalTrollingFootage/commit/31e4755a3830fc73c670463a815f302d7c821c4e)

If you are on Linux, download the **[Automated Installer](http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/)** for DevkitPro depending on your system.

Shoot this into your terminal:

   ```perl devkitARMupdate.pl```
  
The same steps should work for Mac users.

Windows users can use the **[Windows Installer](http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/devkitProUpdater-1.5.3.exe/download)** to install DevkitPro.


Once you setup DevkitPro and libnds, Download the Footage and type this on the terminal:

 ```make ```

and the project should build the footage for you.


**(Don't forget to setup your environment variables to be able to compile the source)**



+ **Linux & Mac users** (replace /path/to/ with your devkitPro installation)
		
    ``export DEVKITPRO=path/to/devkitPro/``
		
    ``export DEVKITARM=${DEVKITPRO}/devkitARM``


**NOTE:** For the ViDSnips API, you need to <u>*purchase*</u> [Icedaddy's](http://www.icedaddy.net/)
plugin to remove the advertisement on the DS, it's on demo mode by default.

You need to place the registration key in `IceDaddy-Reg.h`.


Consoles
-
The footage can be played on:


+ **DS***
+ **DS Lite***
+ **DSi***
+ **3DS (possibly)***
+ **A DS Emulator**


*require flashcarts


Changelog
-
See **CHANGELOG** for more details.


Screenshots
-
![My image](http://www.hakobaito.co.uk/wp-content/uploads/2011/11/Preview.png)        |                        ![My image](http://www.hakobaito.co.uk/wp-content/uploads/2013/01/Screenshot2.png)


Credits
-

Code by hakobyte

Video Plugin API (ViDSnips) by Icedaddy

Testing by Frankie Jax

NFlib library (for libnds) by NightFox

Voices in the original cartoon by lessthannormal01

And anyone else who I missed out.



LICENSE
-

The Art of External Trolling: The Footage, is licensed under the WTFPL License.