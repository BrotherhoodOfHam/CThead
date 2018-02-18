/*
	Volume class implementation


	internal data representation,
	volume[sizeZ, sizeY, sizeX]
*/

#include <algorithm>

#include "Volume.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////

Volume::Volume(QIODevice& volumeData, const Dimensions& dimensions) :
	m_dim(dimensions)
{
	Q_ASSERT(sizeX() > 0);
	Q_ASSERT(sizeY() > 0);
	Q_ASSERT(sizeZ() > 0);

	//Reserve space in buffer
	m_data.resize(sizeX() * sizeY() * sizeZ());

	//Read directly into buffer
	volumeData.read((char*)m_data.data(), m_data.size() * sizeof(ElementType));
}

Volume::Volume(Volume&& other) :
	m_dim(other.m_dim),
	m_data(std::move(other.m_data))
{
	other.m_dim = Dimensions();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
