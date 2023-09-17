## Important observations while trying to create or modify and use an existing library. 
The library downloaded directly from Nicholas' repository (libuopmsb) compiles directly (without any modification) when placed in the 'lib' folder of the specific project.

I created a library.json file that contains the following information:

``` json
{
     "name": "uopmsb",
     "keywords": "lcd, led matrix, sd card, uop_msb",
     "description": "A library for interfacing with sensors and collecting data on the university of plymouth module suppourt board version 4.",
     "version": "1.0.0",
     "author": "Nicholas Outram",
	 "license": "Creative Commons CC0 1.0 Universal",
     "frameworks": ["mbed"],
     "platforms": ["STM 32 boards"]
 }
```

When this file is placed in the 'libuopmsb' folder downloaded, simply to conform with PlatformIO's recommended library structure, the same library comes up with the below error:

Similarly, I re-organised the library to mirror PlatformIO's recomended structure as below:
|--uopmsb

_