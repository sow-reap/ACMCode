<h1>Win11部署dify</h1>
<h2>一、安装docker desktop，然后运行</h2>
<h3>问题一：docker无法正常运行。</h3>
因为windows运行docker desktop需要使用WSL，WSL在安装docker desktop时会自动安装。
<p>解决1：确保“控制面板-程序和功能-Windows功能”的“适用于Linux的Windows子系统”已启用。</p>
<p>解决2：更新WSL，执行：wsl --update。</p>
<p>解决3：切换至WSL 2。</p>
<h3>docker镜像拉取失败</h3>
更改镜像源，点击docker desktop右上角“设置”-“docker engine”,然后添加下面镜像：
<code>
Registry Mirrors:
  https://2a6bf1988cb6428c877f723ec7530dbc.mirror.swr.myhuaweicloud.com/
  https://docker.m.daocloud.io/
  https://hub-mirror.c.163.com/
  https://mirror.baidubce.com/
  https://your_preferred_mirror/
  https://dockerhub.icu/
  https://docker.registry.cyou/
  https://docker-cf.registry.cyou/
  https://dockercf.jsdelivr.fyi/
  https://docker.jsdelivr.fyi/
  https://dockertest.jsdelivr.fyi/
  https://mirror.aliyuncs.com/
  https://dockerproxy.com/
  https://docker.nju.edu.cn/
  https://docker.mirrors.sjtug.sjtu.edu.cn/
  https://docker.mirrors.ustc.edu.cn/
  https://mirror.iscas.ac.cn/
  https://docker.rainbond.cc/
</code>
重启docker。
<h3>发布dify后，提示服务器内部错误</h3>
<p>将下图的.env文件格式由unix转为windows（可以使用Notepad++实现），然后重新部署即可。</p>
![image](https://github.com/user-attachments/assets/fdcff9a8-619a-49b6-904d-7ff5ede9d8f7)
