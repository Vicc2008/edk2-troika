# edk2-motog
UEFI port for Motorola One Action and Motorola One Vision

## Supported Devices (WIP)

Motorola One Vision = kane

Motorola One Action = troika

## Building

### First steps

sudo apt update

sudo apt upgrade

sudo apt install build-essential uuid-dev iasl git nasm gcc-aarch64-linux-gnu abootimg python3-distutils python3-pil python3-git

mkdir edk2-porting

cd edk2-porting

### Next steps (If you have already completed the First steps and don't want issues.)

git clone https://github.com/tianocore/edk2.git --recursive

git clone https://github.com/tianocore/edk2-platforms.git

git clone https://github.com/Vicc2008/edk2-troika.git

cd edk2 && make -C Basetools/

source edksetup.sh

cd ../edk2-troikane

chmod +x build.sh

chmod +x build_common.sh

bash build.sh

## Status

More than likely not working. There might be some messed up memory maps, Maybe something else is messed up? But definately not ready. It is only public __in case someone can help us work on it.__ From what I have heard, devices with a Qualcomm Snapdragon 665 processor are supposedly impossible to use EDK2, but from my 18 years of hearing things are "impossible," that is dumb. I mean, people said things like portable electronics (phones, etc.) and some types of aircraft would be impossible, but here we are today. So lesson is, nothing is impossible.

## Device specs?

__All Phone Models__
> SoC = Exynos 9609
> 
> RAM = 4GB

## Device Picture

<img src="https://www.movilzona.es/app/uploads/2019/10/Motorola-One-Vision-vs-Motorola-One-Action.png" width="1268" height="664" />

Basic   | Spec Sheet
-------:|:--------------------------------------------------------------------
CPU     | Exynos 9609
Memory  | 4GB
Shipped OS | Android 9 pie
Storage | 128GB
Battery | 4000 mAh / 5000 mAh
Display | 6.3" 1080x2520 pixels / 6.3" 1080x2520 pixels
Camera  | Triple 12MP+16MP+5MP / Dual 48MP+5MP
