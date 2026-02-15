# subnet-ipv4

## Table of Contents
+ [Title](#subnet-ipv4)
+ [Description](#description)
+ [Disclaimer](#disclaimer)
+ [Requirement](#requirement)
+ [Project Structure](#project-structure-overkill)
+ [Feature](#feature)
+ [Usage](#usage)
+ [License](#license)

## Description

[^ToC](#table-of-contents)

A personal journey exploring c++ in making (POC) Proof of concept and quickest-canonical project.
**subnet-ipv4** provides the quickest way of having the computed subnets and corresponding IP Host addresses.

## Disclaimer
> [!IMPORTANT]
> *All trademarks, third-party logos/assets, brand names are the property of their respective owner. This project is an independent educational resource and not sanctioned, sponsored, manage by any theird-party trademark holders.*

## Requirement

[^ToC](#table-of-contents)

+ [CMake ***'>=3.28'***]()
+ [Ninja ***'>=1.10'***]()
+ [C/CPP Compiler for ***'>=cxx_std_17'***]()


## Project Structure `overkill`

[^ToC](#table-of-contents)

```bash
subnet-ipv4/
|--- CMakeLists.txt
|--- .repo/fetchcontent/ #REM: External lib with fetchcontent
|--- install/ #REM: The project cmake prefix install
\--- src/
     |--- main/
     |    |--- core/ #REM: project lib
     |    |    |--- cpp/learn_cpp/poc/subnet_ipv4/core/     #REM: .cpp, .cc, .cxx & etc..
     |    |    |--- public/learn_cpp/poc/subnet_ipv4/core/  #REM: public header (include)
     |    |    |--- private/learn_cpp/poc/subnet_ipv4/core/ #REM: internal header
     |    |    \--- CMakeLists.txt
     |    |--- app/
     |    |    |--- cpp/learn_cpp/poc/subnet_ipv4/app/      #REM: .cpp, .cc, .cxx & etc..
     |    |    |--- private/learn_cpp/poc/subnet_ipv4/app/  #REM: internal header
     |    |    \--- CMakeLists.txt
     |    |--- resources/
     |    \--- CMakeLists.txt
     \--- test/
          |--- unit/
          |    |--- cpp/learn_cpp/poc/subnet_ipv4/unit_test/
          |    \--- CMakeLists.txt
          |--- integration/
          |    |--- cpp/learn_cpp/poc/subnet_ipv4/integration_test/
          |    \--- CMakeLists.txt
          \--- CMakeLists.txt
```
## Feature
+ []()

<!-- ## Usage*

[^ToC](#table-of-contents)

### With pre-compiled binary
```bash
#REM: Headless
$ <artifact_bin_name> --headless <ip> <needed_amount_ip_host_address>

#REM: Interactive Text-based UI (REPL)
$ <artifact_bin_name>
> <ip> <needed_amount_ip_host_address>
```
### Compilation, installing, testing and running it
```bash
$ cmake -S . -B build -G "Ninja Multi-Config"
$ cmake --build build [--config <Debug|Release>] [--target <target_name>] [--clean-first] [-j 12]
$ cmake --install build [--config <Debug|Release>] [-j 12]
$ ctest --test-dir build [-C <Debug|Release>] [-L <label_name>] [-VV]

#REM: Headless
$ install/subnet-ipv4/<version>/bin/<artifact_bin_name> --headless <ip> <needed_amount_ip_host_address>

#REM: Interactive Text-based UI (REPL)
$ install/subnet-ipv4/<version>/bin/<artifact_bin_name> 
> <ip> <needed_amount_ip_host_address>
``` -->

## License

[^ToC](#table-of-contents)

[![License GPL v3.0](https://img.shields.io/badge/License-GPL_v3.0-blue?logo=gnu&style=for-the-badge)]()&emsp;[![License AGPL v3.0](https://img.shields.io/badge/License-AGPL_v3.0-blue?logo=gnu&style=for-the-badge)]()