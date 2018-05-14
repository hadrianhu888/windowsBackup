/* Program to replace a sub-string with another */

#include <stdio.h>
#include <string.h>

void replaceSubstring(char [],char[],char[]);

int main(int argc, char * argv [])
{
	char string[100],sub[100],new[100];
	printf("\nEnter a string: ");
	gets(string);
	printf("\nEnter the substring: ");
	gets(sub);
	printf("\nEnter the new substring: ");
	gets(new);
	replaceSubstring(string,sub,new);
	printf("\nThe string after replacing…….\n\n%s\n\n",string);
}

void replaceSubstring(char string[],char sub[],char new[])
{
	int stringLen,subLen,newLen;
	int i=0,j,k;
	int flag=0,start,end;
	stringLen=strlen(string);
	subLen=strlen(sub);
	newLen=strlen(new);

for(i=0;i<stringLen;i++)
{
	flag=0;
	start=i;
	for(j=0;string[i]==sub[j];j++,i++) /* Checks for the substring */
		if(j==subLen-1)
		flag=1; /* flag sets when substring is identified */
		end=i;
	if(flag==0)
		i-=j;
	else
	{
			for(j=start;j<end;j++) /* Delete the substring */
		{
			for(k=start;k<stringLen;k++)
				string[k]=string[k+1];
				stringLen--;
				i--;
		}

for(j=start;j<start+newLen;j++)    /* Inserting new substring */
{
	for(k=stringLen;k>=j;k--)
	string[k+1]=string[k];
	string[j]=new[j-start];
	stringLen++;
	i++;
}
}
}
}
