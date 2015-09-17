/*!	\file viDSnips.h
 	\brief viDSnips player library for DS homebrew projects.
	\details This is the full API for the viDSnips library. 
	In addition to this header you must ensure that IceDaddy-Reg.h is also included in the project.
*/

/*!	\mainpage viDSnips library
	\details viDSnips v3 provides basic video playing functionality to any DS homebrew project.
	\author IceDaddy.net	(icedaddy.net)
	\version 3.0
	\date April 2012

	\note viDSnips 3 is not backward compatible with .vDS media files created for earlier versions.

	\section Overview Overview
	viDSnips is a basic media player for viDSnips (vDS) video files.
	It is intended for playback of short video sequences.
	The video is full screen and runs exclusively. 
	Included with the library are the conversion tools required to convert audio and video to .vDS media file.
	Frame rates are typically 10 or 12 fps.
	Audio and video are synchronised.
	The viDSnips 3 library can be used in any DS homebrew project since it has dependencies upon libNDS only.

	viDSnips is free but users are encouraged to register.
	A small donation (of any amount), to show your appreciation, is all that is required to register at 
	<a href="http://www.icedaddy.net">www.icedaddy.net</a>.
	In doing so you will ensure future support of viDSnips and the development of further DS homebrew libraries.
	Although the free version is fully functioning you do see an initial splash screen when it is initialised.
	By registering this splash screen is not displayed and the registration key will be balid for all future
	versions of viDSnips.

	This documentation is for viDSnips 3. Although there are strong similarities with the earlier versions
	it should be noted that viDSnips 3 is not backward compatible with earlier .vDS version media files.
	See \ref Versions "viDSnip Versions & History" for more information of the differences in order to determine
	which version is most suited to your needs.

	\section Usage How to Use
	Before using viDSnips you will need to convert or create a .vDS media file to play.
	See \ref Conversion "the following section" for details about file format and conversion.

	The viDSnips \ref viDSnips.h "API" is very simple.

	Included with the library is a sample application showing usage with a sample makefile.

	You will need to include the \ref viDSnips.h and \ref IceDaddy-Reg.h files in your project.
	Prior to using viDSnips you will need to setup the filesystem (NitroFS, FAT or any other standard filesystem).
	You will also need to setup the libNDS Simple Sound Engine with the call \em soundEnable();
	There is no need to configure the video or VRAM as viDSnips will setup a minimal configuration for it's
	own needs. However, after you have finished playing the video you will probably want to reconfigure
	the video and VRAM for your own requirements.

	Your project \em makefile will also need to include the viDSnips library (\em viDSnips.a) in the \em LIBS
	setting. The sample makefile given in the example shows what is required.

	\section Conversion Video File Conversion
	There are 2 conversion tools provided:
	 - viDSnips.exe, a Windows utility
	 
	 - cmdviDSnips.exe a DOS utility

	 In addition you will need to download the following third party tools and put them in the same directory
	 as the viDSnips tools (or somewhere accessible on the path):
	 - FFmpeg.exe obtainable from <a href="http://ffmpeg.org">ffmpeg.org</a>

	 - SoX.exe obtainable from <a href="http://sox.sourceforge.net">sox.sourceforge.net</a>

	The simplest way to create a .vDS media file is to use the viDSnips.exe Windows application.
	It's pretty straightforward.

	A viDSnips 3 .vDS file consists of a header, the ADPCM audio followed by the jpg video frames.
	If you want more control over the video and audio you can use the cmdviDSnips.exe DOS utility directly.
	This is the tool that assembles the jpg's and audio data into a single .vDS file. Just run the utility
	to see how to use it.

	FFmpeg and SoX are used by the Windows viDSnips.exe to extract frames from a video file and convert the 
	audio to IMA ADPCM.

	\section Versions viDSnip Versions & History
	viDSnips 1 was a short lived forerunner that was quickly superceded by version 2.
	As such I do not believe there are currently any users of viDSnips 1 and it is obsolete.

	viDSnips 2 used, primarily, the MP3 streaming ability of PALib (plus some other minor functionality).
	This gave viDSnips 2 good quality audio playback (something lacking in version 1) together with 
	reasonably media file size.

	viDSnips 3 has had all external dependencies removed and now sits purely on top of libNDS alone.
	(You will need filesystem support of course but what that is and how it is implemented is no concern
	to viDSnips just so long it can read the media file.) Video frame rates have been improved further 
	leading to far fewer dropped frames. However, with the absents of PALib's MP3 support (actually it is 
	ASLib that provides the MP3 functions within PALib) the audio format has
	been changed to IMA ADPCM. This has resulted in degraded sound quality for the same .vDS media file size.
	Furthermore, viDSnips 3 does not now stream the audio and so the audio file size is a far more important 
	consideration when creating the media files.
	The audio reproduction on emulators seems to be pretty bad but it is much better on a real DS albeit not
	as good as the old MP3 stream.

	So, which is the best version to choose for your project? That will largely depend on whether your project 
	is based upon PALib or not and the type and video you want to play.

	Improving the audio of viDSnips 3 is certainly on the todo list...
*/

#define MAIN_SCREEN			1		//!< Relative screen id for main screen
#define SUB_SCREEN			2		//!< Relative screen id for sub screnn
	
//!	\brief Iinitialise viDSnips and setup the screen for video playback
/*! \details Must be called before any playback is possible. The specified screen is setup as mode 3
	and a VRAM bank allocated (either bank A for the main screen or bank C for the sub screen).
	It is up to the caller to reset the video and VRAM, as required, after viDSnips has completed.
	\param screen	the screen to show the video in
	\param debug	the debug flag that causes some statistics to display on the sub screen after playback
*/
void viDSnips_Init(u8 screen, u8 debug);

//! \brief Plays the specified vDS media file.
/*! \details Loads the specified viDSnips media file from NitroFS or FAT or any other filesystem you
	have setup. The filesystem must be setup by the caller (for example the libNDS call nitroFSInit() 
	would be used to initialise NitroFS).

	The video is played together with any audio. viDSnips runs exclusively and so no user interaction or
	other processing is possible until the video has completed and this function returns.

	The video must be 256 pixels wide and upto 192 pixels high. The video will be vertically centred.
	\param filename	the filename of the viDSnips media file to play
	\return false if there was some error such as the file specified was not a valid viDSnips file
	(or the wrong version)
*/
u16 viDSnips_Play(const char* filename);

//! \brief Display a Jpeg stored in the filesystem.
/*! \details Loads the specified jpeg file and displays it on the screen configured in the viDSnips_Init call.
	The jpeg should be 256 pixels wide and upto 192 pixels high. It will be vertically centred.
	\param filename	the filename of the jpeg file
	\param height	the height (in pixels) of the image
*/
void viDSnips_ShowJpeg(const char* filename, u16 height);
