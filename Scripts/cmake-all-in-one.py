import subprocess


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


