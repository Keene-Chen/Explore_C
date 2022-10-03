<#
Author:   KeeneChen
DateTime: 2021.09.14-19:20:57
Description: 清除build下的.exe文件
#>

$directory = "E:\ZM\C_Language\"
$delObj="build\*.exe"

# -whatIf 假设
Remove-Item $directory\Grammar\*\$delObj 
Remove-Item $directory\Grammar\*\*\$delObj 
Remove-Item $directory\Test\$delObj