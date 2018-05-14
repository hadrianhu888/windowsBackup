# Learn PowerShell array example
#Create simple array of strings 

#set initial array 

$myArray = "abc", "xyz" 

Write-Host $myArray[2]

$myArray[1] = "pqr" 

Write-Host "After: "

Write-Host " " $myArray

Write-Host " " 

#get data type from array 

$myArray.GetType()

Write-Host "Array Length: " $myArray.Length