## **英译中 CLI**

### 使用方法

```bash
# 1. 安装 git-lfs
sudo pacman -S git-lfs
git-lfs install

# 2. 下载仓库
git clone https://github.com/lingllqs/en_2_zh.git
如果数据库文件clone失败，使用`git lfs pull` 命令重新下载

# 3. 安装依赖
ArchLinux: sudo pacman -S sqlite
Ubuntu: sudo apt install sqlite
Fedora: sudo dnf install sqlite


# 进入目录
cd en_2_zh

# 运行: make run
# 安装: make install
# 卸载: make uninstall
```
