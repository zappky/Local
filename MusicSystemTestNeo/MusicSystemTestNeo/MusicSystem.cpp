#include "MusicSystem.h"


CMusicSystem::CMusicSystem(void)
{
}


CMusicSystem::~CMusicSystem(void)
{
}
bool CMusicSystem::InsertBGMTrack(std::string filename){return true;}
bool CMusicSystem::InsertSoundTrack(std::string filename){return true;}
void CMusicSystem::PlayBGMTrack(unsigned short trackindex){}
void CMusicSystem::PlaySoundTrack(unsigned short trackindex){}
void CMusicSystem::SetVolume(float newVolume){}
void CMusicSystem::Mute(){}
void CMusicSystem::Resume(){}
void CMusicSystem::Pause(){}
void CMusicSystem::TranverseBGMTrack(){}
void CMusicSystem::TranverseSoundTrack(){}

bool CMusicSystem::Init(){return true;}
bool CMusicSystem::CleanUp(){return true;}
bool CMusicSystem::Reset(){return true;}
bool CMusicSystem::Release(){return true;}

void CMusicSystem::PrintDebugInformation(){}