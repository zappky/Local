#include <iostream>
#include "MusicSystem.h"
using namespace std;

bool Func2()
{
	std::cout<<"Func2"<<std::endl;
	return true;
}
bool Func1()
{
	std::cout<<"Func1"<<std::endl;
	return true;
}

void main()
{
	//ISoundEngine* MusicEngine = createIrrKlangDevice();
	////ISound* test = MusicEngine->play2D("bgm2.mp3",true,false,true, ESM_AUTO_DETECT, true);
	////std::cout<<test->drop()<<std::endl;
	////test->stop();
	//

	////delete test;
	////MusicEngine->drop();
	//CAudio test;
	//test.Init(MusicEngine->play3D("bgm2.mp3",irrklang::vec3df(0,0,0),true,false,true, ESM_AUTO_DETECT, true));
	//test.SetPosition(1,1,1);
	//std::cout<<test.GetPositionArray3D()[0]<<std::endl;
	//std::cout<<test.GetPositionArray3D()[1]<<std::endl;
	//std::cout<<test.GetPositionArray3D()[2]<<std::endl;


	CMusicSystem* MS = CMusicSystem::GetInstance();
	CAudio test;
	test.Init(MS->engine->play3D("bgm2.mp3",irrklang::vec3df(0,0,0),true,false,true, ESM_AUTO_DETECT, true));
	MS->RegisterAudioAsBgm(&test);
	int choice = 0;
	float testtemp[3] = {1,1,1};
	bool continuee = true;
	while(continuee)
	{
		cin>>choice;
		switch(choice)
		{
			case 1:
				test.Move(1,1,1);
				test.PrintDebugPosition();
				choice = 0;
			break;

			case 4:
				test.Move(-1,-1,-1);
				test.PrintDebugPosition();
				choice = 0;
			break;

			case 2:
				test.SetAudioMaximunDistance(20000000);
				std::cout<<test.GetAudioMinimumDistance()<<std::endl;
				//test.PrintDebugPosition();
				choice = 0;
			break;

			case 3:
				test.SetAudioMaximunDistance(0.1f);
				std::cout<<test.GetAudioMinimumDistance()<<std::endl;
				
				//test.PrintDebugPosition();
				choice = 0;
			break;
			default:
				continuee = false;
				break;
		}
	};
	//std::cout<<test.EnableAudioEffectControl();
	//std::cout<<test.EnableChorusEffect(100,100,5);
	//std::cout<<test.DisableAllAudioEffect();

	//std::cout<<test.StopAndRelease();
	//test.SetVolume(7676);
	//test.audio->setPosition(irrklang::vec3df(10,10,10));
	//std::cout<<test.audio->getPosition().X<<std::endl;
	//std::cout<<test.audio->getPosition().Y<<std::endl;
	//std::cout<<test.audio->getPosition().Z<<std::endl;
	//test.audio->stop();
	//
	//test.audio->drop();
	//delete test.audio;
	//test.CleanUp();
	MS->Exit();
	system("pause");
};