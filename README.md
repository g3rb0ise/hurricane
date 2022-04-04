# hurricane

The Hurricane tool allows to analyze the files of a system with their footprints. 

## Project organization

The project follows the git-flow model.

## Usage
The checkum command displays the footprints of the files in parameters : 

```
hurricane checksum <file1> [ <file2> [...]]
hurricane checksum ./test/checksum/*.test
```
The radar command can detect files located in a database thanks to its footprint (SHA256):

```
radare <database> <file1> [ <file2> [...]]
hurricane radare ./test/radar_database/db1.txt ./test/checksum/*.test
```

Use recursive mode for radare:
```
radare <database> -r <basedir>
hurricane radare ./test/radar_database/db1.txt -r /
```

## Project build

Get information about compilation settings :
```{bash}
make info
```

Compile project:
```{bash}
make
```

Clear project build files:
```
make clear
```

Clear all generated files:
```
make mrproper
```

## Contribution

If you like my work, you can offer me a coffee via [uip](https://utip.io/g3rb0ise).
