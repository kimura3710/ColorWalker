#include <DxLib.h>
#include "ImageMng.h"

ImageMng *ImageMng::s_Instance = nullptr;

ImageMng::ImageMng()
{
}

const Vec_Int & ImageMng::GetID(const std::string& key)
{
	return GetID(key, key);
}

const Vec_Int & ImageMng::GetID(const std::string& key, const  std::string& fileName)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(1);
		imgMap[key][0] = DxLib::LoadGraph(fileName.c_str());
	}
	return imgMap[key];
}

const Vec_Int & ImageMng::GetID(const std::string& key, const Vector2& divCnt, const  Vector2& divSize)
{
	return GetID(key, key, divCnt, divSize);
}

const Vec_Int & ImageMng::GetID(const std::string& key, const  std::string& fileName, const  Vector2& divCnt, const  Vector2& divSize)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(divCnt.x*divCnt.y);
		DxLib::LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imgMap[key][0], true);
	}
	return imgMap[key];
}


ImageMng::~ImageMng()
{
}
