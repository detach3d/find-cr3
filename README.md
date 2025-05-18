# CR3 Finder Kernel Module

This Linux kernel module prints the CR3 value (page table base address) of the current process when loaded.

---

## Build Instructions

```bash
make
```
## Load the Module

```bash
sudo insmod cr3_finder.ko
dmesg | tail
```
You should see something like this:

<img width="380" alt="image" src="https://github.com/user-attachments/assets/666d2f90-91e3-487b-ba9f-bfdc3b964cf7" />


## Unload the Module
```bash
sudo rmmod cr3_finder
```
