# zeromq-cookbook

Delicious ZeroMQ recipes!

# Preinstall

Tested on Ubuntu 20.04(WSL2).

Install `clang` compiler, `zmq` lib and Google unit test `gtest`. We need `python3` to install Google [cpplint](https://github.com/cpplint/cpplint) and latest cmake package.

```bash
 $ sudo apt install -y clang libczmq-dev libgtest-dev python3
```

If you want setup pip3 package bin.

```bash
 $ echo "export PATH=\$PATH:\$HOME/.local/bin" >> .bashrc && source .bashrc
```

Install `cmake`.

```bash
 $ pip3 install --upgrade cmake
```

# Performance and memory analysis

Install [uftrace](https://github.com/namhyung/uftrace) and [valgrind](https://sourceware.org/git/valgrind.git).

```bash
 $ sudo apt -y install uftrace valgrind
```

Do uftrace to find performance tuning points.

```bash
 $ uftrace main
```

Do valgrind to check memory leaks.

```bash
 $ valgrind main
```

# lint

Do Google `cpplint` to lint up code.

```bash
 $ cpplint main
```

## Reference
- [how-to-import-zeromq-libraries-in-cmake](https://stackoverflow.com/questions/41251474/how-to-import-zeromq-libraries-in-cmake/41252437)
- [cppzmq Github](https://github.com/zeromq/cppzmq/releases)
