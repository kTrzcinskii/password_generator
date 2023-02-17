# Password Generator
It's a command line tool to help you easily generate random password. It's inspired by unix's `pwgen`.

## How to use
After cloning the repo, build the project and enter in your command line:
```
./password_generator [...args]
```

## Available arguments
| Argument | Description | Type | Default value |
| -------- |:-----------:|:----:| -------------:|
| --length | The lenght of the password | Number | 8 |
| --only_lower | Only use lower case letter in the password | Boolean | False |
| --include_numbers | Include numbers in the password | Boolean | True |
| --include_special_char | Include special characters in the password (such as `?`, `!`, etc.) | Boolean | False |
| --number | The number of password you want to generate | Number | 1 |

### Passing arguments without value
*The behaviour depends on the type of the argument (Number/Boolean)*

If you do something like:
```
./password_generator --length --only_lower
```
1. Length value will be default one (8) as it's a numeric type.
2. include_numbers will be set to true (so it's the same as `--only_lower=true`)

## Example
Generate 10 passwords that are 15-characters long, include special characters, but use only lower case letters and don't use numbers:
```
./password_generator --number=10 --length=15 --include_numbers=false --include_special_char --only_lower
```

You can do the same thing by:
```
./password_generator --number=10 --length=15 --include_numbers=false --include_special_char=true --only_lower=true
```
