<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1369708577078" ID="ID_1585600468" MODIFIED="1369983255343" TEXT="UI">
<node CREATED="1369708587234" ID="ID_1499323557" MODIFIED="1369709962875" POSITION="right" TEXT="z_index">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      0&gt; n+ &gt; -1
    </p>
    <p>
      o&#20026;&#24403;&#21069;&#65292; n+&#25353;&#22823;&#23567;&#25490;&#21015;&#65292; -1 &#20026;&#38544;&#34255;
    </p>
  </body>
</html></richcontent>
<node CREATED="1369708600562" ID="ID_1625696306" MODIFIED="1369708610812" TEXT="-1=hide"/>
<node CREATED="1369708611421" ID="ID_1936801633" MODIFIED="1369708624156" TEXT="0=current"/>
<node CREATED="1369708624421" ID="ID_1771275714" MODIFIED="1369708703765" TEXT="&gt;0(n+) index"/>
</node>
<node CREATED="1369708720875" ID="ID_69415843" MODIFIED="1369710965109" POSITION="right" TEXT="control">
<node CREATED="1369708734515" ID="ID_1009669052" MODIFIED="1369709965984" TEXT="show">
<node CREATED="1369708783796" ID="ID_1602578350" MODIFIED="1369709351578" TEXT="_status-&gt;show();">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      _status-&gt;setzindex = 0
    </p>
    <p>
      for g in all subcontrols
    </p>
    <p>
      g._status.subshow()
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1369708737453" ID="ID_427138685" MODIFIED="1369708738890" TEXT="hide"/>
<node CREATED="1369708739765" ID="ID_926535697" MODIFIED="1369709977656" TEXT="ref _status(z_index)">
<node CREATED="1369709120781" ID="ID_460496650" MODIFIED="1369709167984" TEXT="relation_zindex "/>
<node CREATED="1369709168640" ID="ID_140711877" MODIFIED="1369709174828" TEXT="absolute_index"/>
<node CREATED="1369709261203" ID="ID_1950905371" MODIFIED="1369709265125" TEXT="cur_zindex"/>
<node CREATED="1369709274765" ID="ID_1082980184" MODIFIED="1369709276718" TEXT="show"/>
<node CREATED="1369709277031" ID="ID_1860817193" MODIFIED="1369709299375" TEXT="subshow"/>
<node CREATED="1369709620109" ID="ID_920473222" MODIFIED="1369709621390" TEXT="hide"/>
<node CREATED="1369709388375" ID="ID_931545197" MODIFIED="1369709397765" TEXT="ref-&gt; control"/>
<node CREATED="1369709404953" ID="ID_320513068" MODIFIED="1369709513296" TEXT="static g_status_priority_queue"/>
</node>
<node CREATED="1369710966375" ID="ID_1692517075" MODIFIED="1369710973343" TEXT="clone"/>
<node CREATED="1369710974015" ID="ID_1005731501" MODIFIED="1369710975546" TEXT="draw"/>
<node CREATED="1369710975890" ID="ID_424481979" MODIFIED="1369710986296" TEXT="onmouse"/>
<node CREATED="1369710986562" ID="ID_1386347121" MODIFIED="1369710995265" TEXT="onLButton"/>
<node CREATED="1369710995656" ID="ID_209589041" MODIFIED="1369711001453" TEXT="onRButton"/>
<node CREATED="1369711175328" ID="ID_1193027792" MODIFIED="1369711184359" TEXT="static register type">
<node CREATED="1369711260812" ID="ID_1407587648" MODIFIED="1369711285140" TEXT="type name"/>
<node CREATED="1369711264062" ID="ID_975945583" MODIFIED="1369711271687" TEXT="* pObject"/>
</node>
<node CREATED="1369711184734" ID="ID_389075282" MODIFIED="1369711203640" TEXT="load(xmlbuffer)"/>
</node>
<node CREATED="1369710252671" ID="ID_1062861447" MODIFIED="1369710263859" POSITION="left" TEXT="type manage"/>
<node CREATED="1369710264796" ID="ID_1538787687" MODIFIED="1369710269875" POSITION="left" TEXT="xmparser"/>
<node CREATED="1369710281562" ID="ID_123836889" MODIFIED="1369983257281" POSITION="left" TEXT="builder">
<node CREATED="1369710928734" ID="ID_396767020" MODIFIED="1369710934656" TEXT="ref-&gt; xmp parser"/>
<node CREATED="1369710905656" ID="ID_249619029" MODIFIED="1369710913578" TEXT="ref-&gt; type manage"/>
<node CREATED="1369710291359" ID="ID_777024980" MODIFIED="1369710298375" TEXT="builder mainpage"/>
<node CREATED="1369710298656" ID="ID_645369158" MODIFIED="1369710892828" TEXT="build controls"/>
</node>
</node>
</map>
