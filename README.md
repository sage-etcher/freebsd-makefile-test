# FreeBSD Makefile Test 😿

Testing make files on FreeBSD, attempting to make it portable aswell. Using
FreeBSD Make, **NOT** GNU Make or POSIX Make.

## Makefile Commands

`makefile`: the main/core makefile; implicitly calls the other makefiles.  
`config.mk`: configuration and variables.  
`build.mk`: handles the whole build process.  

`make -f makefile <command>` or `make <command>`

| command     | description                       |
|:----------- |:--------------------------------- |
| `build`     | compile sources.                  |
| `clean`     | cleans build files.               |
| `install`   | unimplimented.                    |
| `uninstall` | unimplimented.                    |
| `depend`    | generate header dependencies.     |
| `bear`      | generate `compile_commands.json`. |
| `fullclean` | remove all generated files.       |
| `debug`     | print makefile variables.         |

## Dependencies

 - bear
 - pkgconfig
 - libSDL2-devel

## License

BSD 2-Clause License.  
See the attached [LICENSE](/LICENSE) file.
