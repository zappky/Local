#include <iostream>
#include "MusicSystem.h"


void main()
{
	ISoundEngine* MusicEngine = createIrrKlangDevice();
	CAudio test;

	test.audio = MusicEngine->play2D("bgm2.mp3",true,false,true, ESM_AUTO_DETECT, true);
	test.SetVolume(7676);


	system("pause");
};