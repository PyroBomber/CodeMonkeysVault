#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int i, j, n = argc - 1, maxrepeats = 1, wordscount = n, itemp;
	char* temp = new char;
	char** words = new char*[n];
	int* repeats = new int[n];
	for(i = 0; i < n; i++)
	{
		repeats[i] = 1;
		words[i] = argv[i+1];
	}

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if(strcmp(words[j],words[j+1]) > 0)
			{
				temp = words[j];
				words[j] = words[j+1];
				words[j+1] = temp;
			}
		}
	}

	j = 0;

	for(i = 0; i < n - 1; i++)
	{
		if(strcmp(words[i],words[i+1]) == 0) 
		{
			repeats[j]++;
			wordscount--;
			if(repeats[j] > maxrepeats) maxrepeats = repeats[j];
		}
		else
		{
			j++;
		}
	}

	for(i = 0; i < wordscount - 1; i++)
	{
		for(j = 0; j < wordscount - 1 - i; j++)
		{
			if(repeats[j] < repeats[j+1])
			{
				temp = words[j];
				words[j] = words[j+1];
				words[j+1] = temp;

				itemp = repeats[j];
				repeats[j] = repeats[j+1];
				repeats[j+1] = itemp;
			}
		}
	}

	for(i = 0; i < wordscount; i++)
		cout << words[i] << " " << repeats[i] << endl;

	return 0;
}

/*												Я пытался :с
int i, j, n, maxrepeats, wordscount;
	string temp;
	//char** words;
	string* words = new string[argc];
	int* repeats;
if(argc != 1)
{
	cout << argc << endl;
	n = argc - 1;
	maxrepeats = 1;
	wordscount = n;
	repeats = new int[n];
	for(i = 0; i < n; i++)
	{
		repeats[i] = 1;
		words[i] = argv[i+1];
	}
}
else
{
	n = 20;
	maxrepeats = 1;
	string* words = new string[20];
	i = -1;
	do
	{
		i++;
		cin >> words[i];
	}
	while(!words[i].empty());

	n = i;
	wordscount = n;

	for(i = 0; i < n; i++)
		cout << words[i] << endl;

	repeats = new int[n];
	for(i = 0; i < n; i++)
	{
		repeats[i] = 1;
	}
}*/