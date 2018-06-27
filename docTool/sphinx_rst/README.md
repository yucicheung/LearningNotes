
# Sphinx与reStructuredText

## Sphinx简介
- [前言](http://zh-sphinx-doc.readthedocs.io/en/latest/)
  - Sphinx是一种文档工具，可以轻松撰写清晰且优美的文档。是python项目首选的文档工具(python官方文档编写工具)，同时它对C/C++项目也有很好的支持。
  - 它的良好特性
	- *丰富的输出格式*：支持HTML(包括windows帮助文档),LaTeX(可以打印PDF版本),manual pages(man文档)，纯文本
	- *完备的交叉引用*:语义化的标签，可以自动化链接函数，类，引文，术语及相似的片段信息
	- *明晰的分层结构*:可以轻松的定义文档树，并自动化链接同级/父级/下级文章
	- *美观的自动索引*:可以自动生成美观的模块索引
	- *精确的语法高亮*:基于Pygments自动生成语法高亮
	- *开放的扩展*:支持代码块的自动测试，并包含Python模块的自述文档(API docs)等
  - Sphinx使用reStructuredText作为标记语言，并享有Docutils为reStructuredText提供的分析，转换等多种工具。
	- reStructuredText是一种标记语言(像markdown一样，但比较起来更强大)，有自己的语法。语法的作用是使工具能标记到各部分是什么成分，从而工具会知道该转换为什么组成部分。
	- Docutils是一个开源文档处理系统，可以将一般文字转化为有用的格式，如HTML，LaTEX，man-pages,open-document或XML等形式。
	- 总结就是，Sphinx会将reStructuredText源文件转化为丰富的输出格式，并自动产生参考文献和索引等。

- [其他的文档转换工具](http://zh-sphinx-doc.readthedocs.io/en/latest/intro.html#id2)
  - [`pandoc`](http://pandoc.org/):将文档从一种markup形式转化为另一种形式，允许包含的形式包括Markdown,reStructuredText,HTML,LaTeX,docx,EPUB或者MediaWiki markup等语言;


## [Sphinx实战](http://zh-sphinx-doc.readthedocs.io/en/latest/tutorial.html)
- `quickStart`篇
  - `pip install sphinx`;
  - `sphinx-quickstart`进行快速启动，回答问题生成makefile
  - `make html`生成html文档;`make latexpdf`生成pdf文档

## [reStructuredText简介](http://zh-sphinx-doc.readthedocs.io/en/latest/rest.html#rst-primer)
- reST的简单语法(跟markdown标记有相似之处)
