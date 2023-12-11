#include <stdio.h>
#include <list>

using StringList = std::list<const char*>;

void PrintStation(const StringList& printList)
{
	int index = 1;
	for (StringList::const_iterator itr = printList.begin(); itr != printList.end(); ++itr, ++index)
	{
		printf("%02d:%s\n", index, *itr);
	}
}

StringList::const_iterator GetIterator(const StringList& list, const char* name)
{
	for (StringList::const_iterator itr = list.begin(); itr != list.end(); ++itr)
	{
		if (*itr == name)
		{
			return itr;
		}
	}
	return list.end();
}

int main()
{
	StringList stationList_ = {
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori",
		//"Nishi-Nippori",
		"Tabata","Komagome","Sugamo","Otsuka","Ikebukuro","Mejiro",
		"Takadanobaba","Shin-Okubo","Shinjuku","Yoyogi","Harajuku",
		"Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
		//"Takanawa-Gateway",
		"Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
	};

	printf("\n1970\n");
	PrintStation(stationList_);

	StringList::const_iterator insertItr = GetIterator(stationList_, "Tabata");
	stationList_.insert(insertItr, "Nishi-Nippori");

	printf("\n2019\n");
	PrintStation(stationList_);

	insertItr = GetIterator(stationList_, "Tamachi");
	stationList_.insert(insertItr, "Takanawa-Gateway");

	printf("\n2022\n");
	PrintStation(stationList_);

	return 0;
}
