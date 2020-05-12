#pragma once
#include <map>
#include <vector>
#include <string>
#include "Vector2.h"

using Vec_Int = std::vector<int>;

#define IMAGE_ID(KEY) (ImageMng::GetInstance().GetID(KEY))
#define SET_IMAGE_ID(KEY,FNAME) (ImageMng::GetInstance().GetID(KEY,FNAME))

class ImageMng
{
private:
	ImageMng();
	ImageMng(const ImageMng&);
	void operator=(const ImageMng&);

	static ImageMng* s_Instance;
	std::map<std::string, Vec_Int> imgMap;
public:
	~ImageMng();
	static ImageMng &GetInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new ImageMng();
		}
		return (*s_Instance);
	}

	const Vec_Int & GetID(const std::string& key);
	const Vec_Int & GetID(const std::string& key, const std::string& fileName);
	const Vec_Int & GetID(const std::string& key, const  Vector2& divCnt, const Vector2& divSize);
	const Vec_Int & GetID(const std::string& key, const std::string& fileName, const Vector2& divCnt, const Vector2& divSize);
};

