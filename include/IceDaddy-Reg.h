/*
 * IceDaddy-Reg.h.
 *
 *  by IceDaddy (www.icedaddy.net)
 *
 * This is the IceDaddy plugin registration file. 
 * 
 * This file is required by many IceDaddy plugins and must be included in the project
 *  (in GameWorks.h for example) 
 *
 * When you register a plugin add the key as a const declaration in the list below, as:
 *  const char* ICEDADDY_REGISTRATION_<plugin-name>_Key = "<your-key>";
 *
 * The name and emails declarations are required for your project to build properly
 *  even if you are using the free version of a plugin.
 *
 */
 
 #ifndef ICEDADDY_REGISTERED
	#define ICEDADDY_REGISTERED

	const char* ICEDADDY_REGISTRATION_name = "";
	const char* ICEDADDY_REGISTRATION_email = "";
	
	
	const char* ICEDADDY_REGISTRATION_viDSnips_Key = "";

#endif