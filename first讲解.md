### 一、NS3术语解释

​	在实际学习NS3的代码之前，我们首先要了解一些核心概念。这些概念在以后的编程中几乎每次都要用，所以我们很有必要先了解一下以确保我们有牢固的基础。我们要了解的是一些在网络概念里常用但在NS3里具有特殊意义的术语。

​	

#### 1.1 节点

​	在NS3中，我们可以把节点看做一个内部硬件几乎为空的计算机，我们需要为这个空机配置例如网卡、应用程序、网络协议栈等软硬件，从而驱动这台计算机做我们想要做的事。

​	

#### 1.2 应用程序

​	在NS3中，我们配置的节点（计算机）中没有操作系统的概念，有的只是应用的概念。应用要有一些我们设计的活动并被配置在计算机上运行，从而在整个NS3程序中驱动事件的模拟。开发者基于应用专门开发了一些新的应用程序，例如我们在教程中经常看到的`UdpEchoClientApplication`以及`UdpEchoServerApplication`，这两个应用程序组成了一个小型的B/S架构，用于生成和回显数据包。

​	

#### 1.3 信道

​	我们可以把信道想象成我们平时用的网线，计算机之间需要通过网线在进行数据的传输。这里常用的信道根据连接类型分为`CsmaChannel`、`PointToPointChannel`以及`WifiChannel`。`CsmaChannel`就类似于局域网连接，采用csma信道连接的所有节点都是互相连接的状态。`PointToPointChannel`顾名思义就是两个计算机之间点对点的连接。`WifiChannel`类似于我们平时上网的wifi，我们都可以对这些信道上配置这些信道的属性，从而将我们定义的空机安装在信道上。

​	

#### 1.4 网络设备

​	我们可以把网络设备想象成计算机的网卡，空计算机只连接了网线但没有网卡还是无法正常通信。在NS3中，网络设备是为网卡以及驱动的抽象。我们在节点上安装网络设备，使得节点可以通过信道与其他节点进行通信。正如现实中我们的笔记本可以有多张网卡，通过有线连接以及无线连接与其他设备或是互联网连接，NS3里的节点可以通过多个网络设备连接多个信道与其他节点通信。如上面的信道一样，网络设备也根据连接类型分为`CsmaNetDevice`、`PointToPointNetDevice`及`WifiNetDevice`。他们被设计为分别与之对应类型的信道一起工作。

​	

#### 1.5 拓扑助手

​	在NS3中，我们需要把网络设备安装到节点上，把网络设备连接到信道上，给网络设备分配IP地址等等，在NS3中有很多类似于这些的工作。NS3为我们提供了拓扑助手以使得这些工作变得简单。例如，创建一个网络设备，为它添加MAC地址，把这个网络设备安装在节点上，为这个节点配置网络协议栈，最后把网络设备连接到信道上，这些步骤可能需要很多不同的NS3的核心操作。不仅如此，把多个网络设备连接到多个信道上，并把这些独立的网络连接到互联网上将会需要更多的操作。为了我们的方便，NS3提供了拓扑助手类将这些不同的操作组合到一个易于我们使用的模型中。



### 二、NS3模型及编程思想

​	

<svg width="800" height="600" xmlns="http://www.w3.org/2000/svg">
 <!-- Created with Method Draw - http://github.com/duopixel/Method-Draw/ -->
 <g>
  <title>background</title>
  <rect fill="#fff" id="canvas_background" height="602" width="802" y="-1" x="-1"/>
  <g display="none" overflow="visible" y="0" x="0" height="100%" width="100%" id="canvasGrid">
   <rect fill="url(#gridpattern)" stroke-width="0" y="0" x="0" height="100%" width="100%"/>
  </g>
 </g>
 <g>
  <title>Layer 1</title>
  <polyline stroke-linecap="round" id="svg_65" points="-397.5,634.4375 -397.5,634.4375 " fill-opacity="null" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <rect id="svg_66" height="548" width="234" y="20.4375" x="34.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#DDDDDD"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_68" y="55.4375" x="122.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Node</text>
  <rect id="svg_69" height="66" width="149" y="79.4375" x="91.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_73" y="119.4375" x="109.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Application</text>
  <rect id="svg_76" height="67" width="153" y="108.4375" x="60.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_77" y="149.4375" x="82.5" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Application</text>
  <ellipse ry="48" rx="105" id="svg_78" cy="288.4375" cx="144.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_79" y="295.4375" x="65.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Protocol Stack</text>
  <rect stroke="#000" id="svg_80" height="66" width="149.999996" y="425.4375" x="80.500004" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_83" y="468.4375" x="100.5" stroke-width="0" stroke="#ffffff" fill="#000000">NetDevice</text>
  <rect stroke="#000" id="svg_85" height="66" width="149.999996" y="460.4375" x="56.500004" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_86" y="502.4375" x="77.5" stroke-width="0" stroke="#ffffff" fill="#000000">NetDevice</text>
  <rect id="svg_87" height="548" width="234" y="21.4375" x="528.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#DDDDDD"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_88" y="56.4375" x="617.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Node</text>
  <rect id="svg_89" height="66" width="149" y="80.4375" x="586.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_90" y="120.4375" x="604.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Application</text>
  <rect id="svg_91" height="67" width="153" y="109.4375" x="555.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_92" y="150.4375" x="577.5" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Application</text>
  <ellipse ry="48" rx="105" id="svg_93" cy="289.4375" cx="639.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_94" y="296.4375" x="560.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Protocol Stack</text>
  <rect stroke="#000" id="svg_95" height="66" width="149.999996" y="426.4375" x="575.500004" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_96" y="469.4375" x="595.5" stroke-width="0" stroke="#ffffff" fill="#000000">NetDevice</text>
  <rect stroke="#000" id="svg_97" height="66" width="149.999996" y="461.4375" x="551.500004" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_98" y="503.4375" x="572.5" stroke-width="0" stroke="#ffffff" fill="#000000">NetDevice</text>
  <rect stroke="#000" id="svg_99" height="71.999999" width="149" y="394.437501" x="331.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="#ffffff"/>
  <rect stroke="#000" id="svg_101" height="72.000001" width="153" y="462.4375" x="309.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_102" y="443.4375" x="360.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Channel</text>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_103" y="510.4375" x="339.5" fill-opacity="null" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Channel</text>
  <path id="svg_104" d="m94.5,199.4375" opacity="0.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <line stroke="#000" stroke-linecap="null" stroke-linejoin="null" id="svg_105" y2="240.437497" x2="146.5" y1="176.4375" x1="145.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="none"/>
  <line stroke="#000" stroke-linecap="null" stroke-linejoin="null" id="svg_106" y2="425.437501" x2="147.5" y1="338.4375" x1="147.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_107" y2="242.4375" x2="640.5" y1="177.4375" x1="640.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_108" y2="425.4375" x2="641.5" y1="337.4375" x1="641.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="none"/>
  <line stroke-dasharray="2,2" stroke-linecap="null" stroke-linejoin="null" id="svg_109" y2="421.4375" x2="331.5" y1="453.4375" x1="230.5" fill-opacity="null" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_110" y2="448.4375" x2="575.5" y1="417.4375" x1="480.5" fill-opacity="null" stroke-opacity="null" stroke-dasharray="2,2" stroke-width="1.5" stroke="#000" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_111" y2="504.4375" x2="309.5" y1="497.4375" x1="206.5" fill-opacity="null" stroke-opacity="null" stroke-dasharray="2,2" stroke-width="1.5" stroke="#000" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_112" y2="499.4375" x2="551.5" y1="505.4375" x1="462.5" fill-opacity="null" stroke-opacity="null" stroke-dasharray="2,2" stroke-width="1.5" stroke="#000" fill="none"/>
  <rect id="svg_113" height="84" width="66" y="160.4375" x="238.5" stroke-opacity="null" stroke-width="1.5" stroke="#000" fill="#ffffff"/>
  <text xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_114" y="208.4375" x="322.5" stroke-opacity="null" stroke-width="0" stroke="#000" fill="#000000">Packet(s)</text>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_115" y2="308.4375" x2="283.5" y1="245.4375" x1="282.5" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <line stroke="#000" stroke-linecap="null" stroke-linejoin="null" id="svg_116" y2="310.4375" x2="284.5" y1="281.437501" x1="305.5" stroke-opacity="null" stroke-width="3" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_117" y2="310.4375" x2="282.5" y1="281.4375" x1="260.5" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <path d="m682.5,180.4375c0,0 -0.38269,0.076126 0,1c0.541199,1.306564 1,3 1,5c0,2 -0.68927,5.080246 0,8c0.513733,2.176254 1,5 1,7c0,3 0,8 0,12c0,4 1,8 1,12c0,5 0,11 0,16c0,5 1,10 1,15c0,6 -0.494873,12.020447 0,18c0.501709,6.062042 1,12 1,19c0,6 0,12 0,19c0,6 -1,12 -1,19c0,7 -0.498291,13.937958 -1,20c-0.494873,5.979553 0.577393,12.023865 0,19c-0.501709,6.062042 -0.903381,13.016907 -2,19c-0.91925,5.015472 -1,12 -2,18c-1,6 -1.496216,10.907776 -2,15c-0.488708,3.970032 -1.188354,7.943665 -2,11c-1.308777,4.928192 -1.633423,10.022491 -2,13c-0.503784,4.092224 -1.048706,8.289124 -3,13c-1.379761,3.331085 -2.847229,5.041321 -4,9c-0.884155,3.036163 -2,6 -3,9c-1,3 -2,6 -3,8c-1,2 -3.190308,3.881531 -5,7c-1.122314,1.93399 -3.418884,3.418854 -5,5c-1.581116,1.581146 -2.881531,4.190277 -6,6c-1.934021,1.122345 -3.881531,2.190277 -7,4c-1.934021,1.122345 -5.132996,1.569519 -9,3c-4.194336,1.551605 -7.977356,3.095459 -12,4c-4.974792,1.118652 -9,1 -13,2c-4,1 -7.907776,1.496216 -12,2c-4.962524,0.610901 -9.01947,0.605835 -13,1c-5.074219,0.502441 -9.024353,0.507324 -14,1c-5.074219,0.502441 -10.024353,0.507324 -15,1c-5.074219,0.502441 -8.925781,1.497559 -14,2c-4.975647,0.492676 -9.925781,1.497559 -15,2c-4.975647,0.492676 -9.907776,0.496216 -14,1c-4.962524,0.610901 -9.907776,0.496216 -14,1c-1.985016,0.244385 -6,0 -8,0c-3,0 -7.051636,-0.640747 -11,0c-3.121429,0.506531 -7,1 -11,1c-4,0 -9,0 -13,0c-4,0 -8.925781,0.502441 -14,0c-4.975677,-0.492676 -10,0 -15,0c-5,0 -11,-1 -17,-1c-5,0 -8.925781,-0.497559 -14,-1c-3.98053,-0.394165 -8,-1 -13,-1c-4,0 -9,0 -15,0c-4,0 -7.925781,-0.497559 -13,-1c-3.98053,-0.394165 -10.037476,-0.389099 -15,-1c-4.092224,-0.503784 -9.013641,-0.670105 -13,-1c-6.062042,-0.501709 -11,-1 -16,-1c-5,0 -9,0 -14,0c-6,0 -12,0 -16,0c-4,0 -9,-1 -13,-1c-5,0 -8.907791,-0.496216 -13,-1c-3.970032,-0.488708 -7,-1 -11,-1c-4,0 -8.080246,-0.31073 -11,-1c-2.176254,-0.513733 -3.152237,-0.234619 -5,-1c-1.306564,-0.541199 -2.152237,-1.234619 -4,-2c-2.613129,-1.082397 -4.06601,-2.877655 -6,-4c-3.118484,-1.809723 -5,-3 -6,-4c-1,-1 -2,-2 -3,-3c-1,-1 -1.692551,-2.186005 -3,-4c-1.653809,-2.294525 -3,-3 -4,-5c-1,-2 -1,-4 -2,-6c-1,-2 -1.679642,-4.025818 -2,-6c-0.506546,-3.121429 -1.519455,-5.038727 -2,-8c-0.506546,-3.121429 -1.511261,-7.029968 -2,-11c-0.503769,-4.092224 -1.389084,-8.037476 -2,-13c-0.503769,-4.092224 -2,-9 -2,-13c0,-4 -0.408768,-9.029205 -1,-15c-0.502441,-5.074219 -1,-9 -1,-14c0,-4 0,-8 0,-12c0,-4 -1,-7 -1,-11c0,-4 0.488739,-7.029968 0,-11c-0.503769,-4.092224 -1,-8 -1,-13c0,-6 0,-10 0,-15c0,-7 0,-13 0,-20c0,-6 0,-12 0,-17c0,-6 1,-11 1,-16c0,-4 1,-9 1,-14c0,-4 0.496231,-8.907776 1,-13c0.488739,-3.970032 -0.494888,-10.020447 0,-16c0.501709,-6.062042 0.505112,-13.020447 1,-19c0.501709,-6.062042 1,-12 1,-17c0,-5 0,-10 0,-13c0,-2 0,-5 0,-7c0,-2 0,-4 0,-7c0,-2 0,-4 0,-6c0,-1 0,-2 0,-3l1,0l0,-1" id="svg_118" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <path d="m163.5,197.4375c0,0 0,-1 1,-2c1,-1 2.61731,-3.076126 3,-4c0.541199,-1.306564 1.61731,-2.076126 2,-3c0.541199,-1.306564 2,-1 2,-2c0,-1 0.693436,-1.458801 2,-2c0.923874,-0.38269 0.693436,-1.458801 2,-2c0.923874,-0.38269 1.693436,-0.458801 3,-1c0.923874,-0.38269 2,0 3,-1l1,0l0,-1l1,0" id="svg_119" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <path d="m204.5,189.4375c0,0 -1.292892,0.707108 -2,0c-0.707108,-0.707108 -1.292892,-0.292892 -2,-1c-0.707108,-0.707108 -1.292892,-1.292892 -2,-2c-0.707108,-0.707108 -1.292892,-0.292892 -2,-1c-0.707108,-0.707108 -0.292892,-1.292892 -1,-2c-0.707108,-0.707108 -1.292892,-0.292892 -2,-1c-0.707108,-0.707108 -1.292892,-0.292892 -2,-1c-0.707108,-0.707108 -1,-1 -1,-2l-1,0" id="svg_120" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <path d="m664.5,196.4375c0,0 0.292908,-0.292892 1,-1c0.707092,-0.707108 2,-2 4,-5c2,-3 3,-4 4,-5c1,-1 2.292908,-1.292892 3,-2c0.707092,-0.707108 1,-1 2,-1c1,0 1,-1 2,-1l1,0l0,-1l1,0" id="svg_122" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <path d="m709.5,196.4375c0,0 0.707092,-1.292892 0,-2c-0.707092,-0.707108 -2,-1 -3,-2c-1,-1 -1.852722,-2.173096 -3,-3c-1.813965,-1.307449 -3.292908,-1.292892 -4,-2c-0.707092,-0.707108 -0.292908,-0.292892 -1,-1c-0.707092,-0.707108 -0.69342,-1.458801 -2,-2c-0.923889,-0.38269 -2.69342,-1.458801 -4,-2c-0.923889,-0.38269 -1,-1 -2,-1l-1,0l0,-1" id="svg_123" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_125" y2="224.4375" x2="197.5" y1="91.4375" x1="306.5" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <line stroke-linecap="null" stroke-linejoin="null" id="svg_126" y2="226.4375" x2="195.5" y1="203.4375" x1="195.5" stroke-opacity="null" stroke-width="3" stroke="#000" fill="none"/>
  <line stroke="#000" stroke-linecap="null" stroke-linejoin="null" id="svg_127" y2="228.4375" x2="195.5" y1="224.4375" x1="218.5" stroke-opacity="null" stroke-width="3" fill="none"/>
  <text stroke="#000" transform="matrix(0.9704693823032073,0,0,1.0177262503874684,5.861073228575534,2.214260566373782) " xml:space="preserve" text-anchor="start" font-family="Helvetica, Arial, sans-serif" font-size="24" id="svg_129" y="83.4375" x="318.5" stroke-opacity="null" stroke-width="0" fill="#000000">Socket-like API</text>
 </g>
</svg>



​	主要的编程思想（OSI模型自底向上）：

| **应用层**     |
| -------------- |
| **表示层**     |
| **会话层**     |
| **传输层**     |
| **网络层**     |
| **数据链路层** |
| **物理层**     |

​	1.创建节点。

​	2.选择连接类型，设置连接属性，用连接的install方法为节点安装网络设备，并用网络设备容器保存。注意：如有多个连接，一定依次按以上步骤一个一个来。（物理层、网络层，连接这两个层）

​	3.为节点安装协议栈。（网络层、传输层）

​	4.地址助手设置基准地址。

​	5.用地址助手的Assign方法为设网络设备容器内的设备分配地址，并用接口助手保存。（连接传输层与网络层）

​	6.设置应用层服务器，客户端。设置各种属性、起止时间。（应用层）

​	7.开始模拟，销毁模拟。

​	**以上顺序不能颠倒！**

> helper类的install方法都是用来连接两个层的。

​	

### 三、first.cc

#### 	3.1 代码学习

​	打开ns3.31目录下的`examples/tutorial`，把例子拷到`scratch`文件夹下。因为 waf 要进入这个文件夹来进行编译运行，故我们需要把要运行的文件放入这个文件夹，这里为了图省事，一次性把七个例子全部复制过去。

```shell
$ cd /home/zcl/ns-allinone-3.31/ns-3.31/
$ cp examples/tutorial/*.cc scratch
```

​	然后在vscode里打开`first.cc`，代码如下

```C++
/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1
//    point-to-point
//
 
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

int
main (int argc, char *argv[])
{
  CommandLine cmd (__FILE__);
  cmd.Parse (argc, argv);
  
  Time::SetResolution (Time::NS);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create (2);

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

  NetDeviceContainer devices;
  devices = pointToPoint.Install (nodes);

  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");

  Ipv4InterfaceContainer interfaces = address.Assign (devices);

  UdpEchoServerHelper echoServer (9);

  ApplicationContainer serverApps = echoServer.Install (nodes.Get (1));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (10.0));

  UdpEchoClientHelper echoClient (interfaces.GetAddress (1), 9);
  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

  ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
  clientApps.Start (Seconds (2.0));
  clientApps.Stop (Seconds (10.0));

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}

```

​	

​	下面进行详细学习。

​	

* 1-15行代码：

```C++
/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
```

​	是一些文件说明，包含文件类型，版权信息等。

​	

* 17-21行代码：

```C++
#include "ns3/core-module.h" //Core模块定义了NS3的核心功能（如模拟事件、事件调度）
#include "ns3/network-module.h" //network模块定义了NS3的基本网络组件（如网络结点、分组和地址）
#include "ns3/internet-module.h"//internet模块定义了NS3的TCP/IP协议栈
#include "ns3/point-to-point-module.h"//点对点模块
#include "ns3/applications-module.h"//Application模块定义了应用层分组收发模型（如贪婪模型、ON/OFF模型）
```

​	包含了我们在这个项目中所使用到的头文件。NS3的全部头文件位于`ns-allinone-3.31/ns-3.31/build/ns3`文件夹下，因我们在编译时的文件夹是`ns-allinone-3.31/ns-3.31/build`，所以我们在包含头文件时要加上头文件的目录，也就是`ns3`这个文件夹。

​	

* 23-28行代码：

```C++
// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1
//    point-to-point
//
```

​	大体描述了整个模拟网络的拓扑，后期我们在自己编写程序的时候也要养成这种画拓扑的习惯，以方便别人看懂我们的程序及代码。

​	

* 30行代码：

```C++
using namespace ns3;
```

​	指定命名空间为ns3，这样我们在敲NS3代码的时候不需要加作用域符号 `ns3::` ，但如果我们在NS3的代码里要使用常见的`cout`命令输出某个变量的值，则需要加作用域`std::cout`。

​	

* 32行代码：

```C++
NS_LOG_COMPONENT_DEFINE("FirstScriptExample");
```

​	此行声明了一个名为`FirstScriptExample`的日志记录组件，该组件允许我们通过引用名称来启用和禁用控制台消息日志记录。可以通过后面的`LogComponentEnable`函数或通过命令行改变环境变量来启动或禁用对应的日志组件。

​	

* 34-36行代码：

```C++
int 
main(int argc, char *argv[])
  {
```

​	是主函数，就跟普通的C++程序一样，每个程序都要有一个主函数。

​	

* 37-38行代码：

```C++
CommandLine cmd(__FILE__);
cmd.Parse(argc, argv);
```

​	声明了一个命令行解析器，并读取了命令行参数。我们可以在命令行解析器里设置参数，在执行程序时通过指定具体参数的值达到灵活编程的特点。

​	

* 40行代码：

```c++
Time::SetResolution (Time::NS);
```

​	设置系统的最小模拟时间单位为纳秒，如果不写此条语句，系统默认最小分辨率为1ns。

​	

* 41-42行代码：

```C++
LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);
```

​	设置了日志组件的信息，可以通过修改这里的等级以获取不同详细程度的输出。

​	系统中定义了七个级别的详细程度不断提高的日志消息：

* LOG_ERROR ——记录错误消息。

* LOG_WARN ——记录警告消息。

* LOG_DEBUG ——记录相对少见的ad-hoc调试消息。

* LOG_INFO ——记录有关程序进度的信息性消息。

* LOG_FUNCTION ——记录每个被调用函数的信息。

* LOG_LOGIC ——记录一个函数内描述逻辑流程的信息。

* LOG_ALL ——记录上述所有内容。

  ​    

​	  对于每个LOG_TYPE，还有一个LOG_LEVEL_TYPE，因此，LOG_ERROR和LOG_LEVEL_ERROR以及LOG_ALL和LOG_LEVEL_ALL在功能上是等效的。除了记录本级别外，还记录其下所有级别。例如，启用LOG_INFO将仅启用NS_LOG_INFO提供的消息，而启用LOG_LEVEL_INFO还将启用在其之下的NS_LOG_DEBUG，NS_LOG_WARN和NS_LOG_ERROR提供的消息。

​	还提供了无论选择任何日志记录级别或组件都始终显示的无条件日志记录。

* NS_LOG_UNCOND ——无条件记录关联的消息。

    ​	

* 44-45行代码：

```C++
NodeContainer nodes;
nodes.Create (2);
```

​	

​	声明了一个`NodeContainer`类的节点容器，通过`Create`函数借助Vector容器的尾插法将创建的节点插入到容器中。

​	

* 47-49行代码

```C++
PointToPointHelper pointToPoint;
pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));
```



​	声明了一个`PointToPointHelper`类的点对点连接信道，并通过调用`SetDeviceAttribute`以及`SetChannelAttribute`由“工厂”设置了信道的传输速率为5Mbps，信道延迟为2ms。

​	

* 51-52行代码：

```C++
NetDeviceContainer devices;
devices = pointToPoint.Install (nodes);
```

​	通常我们使用助手将NS3网络设备安装在节点上。助手的`Install()`函数通常以包含着一定数量的`Ptr<Node>`类型的指向具体节点的指针的`NodeContainer`作为参数。对于`NodeContainer`中的每个节点，助手都会实例化一个网络设备，为设备添加MAC地址以及一个队列，然后将这个设备安装在节点上。对于每个设备，助手还将把设备添加到容器中以供调用者以后使用。

​	

* 54-55行代码：

```C++
InternetStackHelper stack;
stack.Install (nodes);
```

​	

​	这两行代码里，第一行定义了一个`InternetStackHelper`类的stack的变量，第二行调用了`Install()`方法为每一个节点安装网络协议栈。

​	

* 57-58行代码：

```C++
Ipv4AddressHelper address;
address.SetBase ("10.1.1.0", "255.255.255.0");
```

​	`Ipv4AddressHelper`是一个能执行简单的IPv4地址分配的脚本。程序里的这两行代码定义了一个ipv4地址助手，并设置其要分配的ip网段、子网掩码。其中的地址默认从1开始分配（不写第三个参数）。

​	

* 60行代码：

```C++
Ipv4InterfaceContainer interfaces = address.Assign (devices);
```

​		程序中的这行代码，声明了一个`Ipv4InterfaceContainer`类型的变量interfaces，并调用`Ipv4AddressHelper`的Assign()方法来对地址进行分配，由于两个节点上分别有一个网络设备，ipv4助手为他们分配了10.1.1.1以及10.1.1.2两个地址。

​	

​	下面进入应用层：

  

* 62-66行代码：

```C++
UdpEchoServerHelper echoServer (9);

ApplicationContainer serverApps = echoServer.Install (nodes.Get (1));
serverApps.Start (Seconds (1.0));
serverApps.Stop (Seconds (10.0));
```

​	

​	代码第一行首先定义了一个`UdpEchoServerHelper`助手，使用`SetAttribute()`方法指定了Udp回声服务器工作在9号端口上。第二行调用`UdpEchoServerHelper`类的`install()`方法并传入1号节点的地址，方法内为1号节点安装了Udp回声服务器，并定义了一个应用程序容器用于接收安装成功的回声服务器。第2-3行代码为应用程序容器内的每一个应用程序设置回声服务器自模拟启动后1.0s开始监听并接收来自9号端口的数据，并于模拟启动后10.0s停止。

> 注意！必须设置停止时间，否则模拟启动后，销毁程序会因为事件未结束而不能结束整个程序。

​	

* 68-75行代码：

```C++
UdpEchoClientHelper echoClient (interfaces.GetAddress (1), 9);
echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
clientApps.Start (Seconds (2.0));
clientApps.Stop (Seconds (10.0));
```

​	

​	程序代码里为udp回声客户端指定向接口序号为1的地址的9号端口发送消息。这里必须指定为Udp回声服务器所在接口的地址以及端口号才行。

​	Udp回声客户端通过`SetAttribute()`方法为相应属性赋值，设置了发送数据包个数、大小，以及数据包之间的发送间隔。同样如回声服务器那样，用`install()`方法传入0号节点的地址，为0号节点安装Udp客户端服务器，并定义了一个应用程序容器用于接收安装成功的返回的回声客户端。并通过应用程序容器为echoClient设置了模拟启动后2.0s向结点1的9号端口发送一个1024字节的UDP数据包，同样在模拟启动后10.0s后停止。

> 注意！必须设置停止时间，否则模拟启动后，销毁程序会因为事件未结束而不能结束整个程序。

​	

* 77-79行代码：

```C++
Simulator::Run ();
Simulator::Destroy ();
return 0;
```

​	启动模拟，并销毁模拟。程序结束。

​	

#### 3.2 编译运行

​	下面来运行程序：

​	打开命令行，进入ns3.31目录，进行编译运行：

```shell
$ cd ns-allinone-3.31/ns-3.31/
$ ./waf --run scratch/first
```

​	会看到以下输出：

![image-20200822001323007](http://r.photo.store.qq.com/psc?/V53mQfQh1FnNCr2V9md70Xppby3h3SOQ/TmEUgtj9EK6.7V8ajmQrECDfviMHGpLiDYlMaCAEDIqdErlIeW*7rpMI79cVd9FHY2ehyEkhhlHXcUWaUTCVln2KXZ*a0gkmN56w836vONI!/r)

​	2秒时客户端向10.1.1.2的9号端口发送了1024字节的数据包，2.00369秒时，服务器收到了来自10.1.1.1的49153端口发送的1024字节的数据包，但因为发送成功后要应答，所以服务器要原路发送应答，所以同样服务器在同一时间也向10.1.1.1的49153端口发送了1024字节的数据包，2.00737秒，客户端接收到来自10.1.1.2的9号端口发送的1024字节的数据包。

​	

​	下面进行可视化模拟：

```shell
$ ./waf --run scratch/first --vis
```

​	点击可视化界面上的`Simulate`按钮或按F3键，启动模拟，在2s停下，将会看到以下内容：

![image-20200822010405618](http://r.photo.store.qq.com/psc?/V53mQfQh1FnNCr2V9md70Xppby3h3SOQ/TmEUgtj9EK6.7V8ajmQrEEN0gSn1B2.UghqlmS7Bw4Dv8Og0OsdpzGSz3V5fQ1sgxwjP1TsWzw0pPyEU7sfHuopJz6bU7aHbaQgHtFIqPrU!/r)

​	能看到双向的数据流。同样，随着时间的前进命令行也会跳出发包收包的消息。