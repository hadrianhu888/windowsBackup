﻿Clear-Host\

# This is a comment 

$userReply = ""

while ($userReply -ne "Who is there?")
{
    $userReply = read-host "Knock knock!"
}
Clear-Host
while ($userReply -ne "Orange who?")
{
    $userReply = read-host "Orange."
}

Clear-Host

Write-Output "Orange you glad you created this PowerShell script?"

Start-Host

while ($userReply -ne "Who is there?")
{
    $userReply = read-host "Knock knock!"
}

Clear-Host

while ($userReply -ne "Orange who?")
{
    $userReply = read-host "Orange."
}

Clear-Host

Write-Output "Oranges are oranges but this is PowerShell scripting!"

Start-Sleep -Seconds 5

Clear-Host

while ($userReply -ne "Who is there?")
{
    $userReply = read-host "Knock knock!"
}
W
Clear-Host

while ($userReply -ne "Banana who?")
{
    $userReply = read-host "Banana."
}

Clear-Host

Write-Output "Orange you glad I didn't say orange?"

Start-Sleep -Seconds 5

Clear-Host

Write-Output "The Knock Knock Joke"
Write-Output ""
Write-Output "Copyright 2006 - Jerry Lee Ford, Jr."

Start-Sleep -Seconds 3

Clear-Host



