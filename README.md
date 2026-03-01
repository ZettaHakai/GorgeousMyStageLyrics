# Mystical Ninja Starring Goemon: Gorgeous My Stage Mod

This is a mod for Goemon 64: Recompiled that gives multiple config options for lyric changes. 

### Tools
You'll need to install `clang` and `make` to build this template.
* On Windows, using [chocolatey](https://chocolatey.org/) to install both is recommended. The packages are `llvm` and `make` respectively.
  * The LLVM 19.1.0 [llvm-project](https://github.com/llvm/llvm-project) release binary, which is also what chocolatey provides, does not support MIPS correctly. The solution is to install 18.1.8 instead, which can be done in chocolatey by specifying `--version 18.1.8` or by downloading the 18.1.8 release directly.
* On Linux, these can both be installed using your distro's package manager. You may also need to install your distro's package for the `lld` linker. On Debian/Ubuntu based distros this will be the `lld` package.
* On MacOS, these can both be installed using Homebrew. Apple clang won't work, as you need a mips target for building the mod code.

On Linux and MacOS, you'll need to also ensure that you have the `zip` utility installed.

You'll also need to grab a build of the `RecompModTool` utility from the releases of [N64Recomp](https://github.com/N64Recomp/N64Recomp). You can also build it yourself from that repo if desired.

### Building
* First, run `make` (with an optional job count) to build the mod code itself.
* Next, run the `RecompModTool` utility with `mod.toml` as the first argument and the build dir (`build` in the case of this template) as the second argument.
  * This will produce your mod's `.nrm` file in the build folder.
  * If you're on MacOS, you may need to specify the path to the `clang` and `ld.lld` binaries using the `CC` and `LD` environment variables, respectively.
  