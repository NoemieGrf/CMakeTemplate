import subprocess
import argparse

# File structure:
# 
# root/
#  |-- llvm-project/
#  |-- build-llvm.py
# 
# Directory 'root/llvm-project/' is the git repo of LLVM.
# Run: 'python build-llvm.py --build'
# Directory ./build will be generated under root.
# Run: 'python build-llvm.py --install'
# The LLVM will be installed in computer.
#
# After build and install, file structure:
# 
# root/
#  |-- llvm-project/
#  |-- build/
#  |-- build-llvm.py
#  |-- build.log
#  |-- install.log


def run(args_list: list[str], fp) -> None:
    args: str = ' '.join(args_list)
    fp.write(f'{args}\n')
    print(args)

    with subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True) as proc:
        for line in proc.stdout:
            print(line, end='')
            fp.write(line)

    rc = proc.returncode
    fp.write(f'finished with code {rc}\n')
    print(f'finished with code {rc}')
    pass


def gen_and_build(fp) -> None:
    gen_args_list: list[str] = ['cmake',
                            '-S ./llvm-project/llvm',
                            '-B ./build/',
                            '-DCMAKE_BUILD_TYPE=Release',
                            #'-DLLVM_ENABLE_PROJECTS=all',
                            '-DCMAKE_CXX_COMPILER=clang++',
                            '-DCMAKE_C_COMPILER=clang']
    
    run(gen_args_list, fp)

    build_args_list: list[str] = ['cmake',
                                  '--build ./build/',
                                  '--config Release',
                                  '-j12']
    
    run(build_args_list, fp)
    pass


def install(fp) -> None:
    args_list: list[str] = ['cmake',
                            '--install',
                            './build/',
                            '--prefix "D:/Programmes/llvm-src-build/"']
    
    run(args_list, fp)
    pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Cmake all in one')
    parser.add_argument('-B', '--build', action='store_true', default=False, help='generate and build')
    parser.add_argument('-I', '--install', action='store_true', default=False, help='install')

    args = parser.parse_args()

    if args.build:
        with open('build.log', 'w') as fp:
            gen_and_build(fp)
    elif args.install:
        with open('install.log', 'w') as fp:
            install(fp)

    pass
    
