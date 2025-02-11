//////////////////////////////////////////////////////////////////////////////////
// SPARK particle engine														//
// Copyright (C) 2008-2013 - Julien Fryer - julienfryer@gmail.com				//
//																				//
// This software is provided 'as-is', without any express or implied			//
// warranty.  In no event will the authors be held liable for any damages		//
// arising from the use of this software.										//
//																				//
// Permission is granted to anyone to use this software for any purpose,		//
// including commercial applications, and to alter it and redistribute it		//
// freely, subject to the following restrictions:								//
//																				//
// 1. The origin of this software must not be misrepresented; you must not		//
//    claim that you wrote the original software. If you use this software		//
//    in a product, an acknowledgment in the product documentation would be		//
//    appreciated but is not required.											//
// 2. Altered source versions must be plainly marked as such, and must not be	//
//    misrepresented as being the original software.							//
// 3. This notice may not be removed or altered from any source distribution.	//
//////////////////////////////////////////////////////////////////////////////////

#include <SPARK_Core.h>

namespace SPK
{
	void DataSet::init(unsigned int nbData)
	{
		destroyAllData();

		if (this->nbData != nbData)
		{
			SPK_DELETE_ARRAY(dataArray);
			dataArray = SPK_NEW_ARRAY(Data*,nbData);
			for (unsigned int i = 0; i < nbData; ++i)
				dataArray[i] = NULL;
			this->nbData = nbData;
		}
	}

	void DataSet::setData(unsigned int index,Data* data)
	{
		SPK_DELETE(dataArray[index]);
		dataArray[index] = data;
	}

	void DataSet::destroyAllData()
	{
		for (unsigned int i = 0; i < nbData; ++i)
			setData(i,NULL);
		initialized = false;
	}
}
