---
description: 專案紀錄
---

# SUT Project

1. 蘇寧只對接ISSSP
2. B2B先做B2C不趕
3. 目前兩兩個倉別\(大富+菜鳥\)
4. 庫存分開管理
   1. \(B2B\)SAP ERP--&gt;ISSSP--&gt;菜鳥，準時達
   2. \(B2C\)SAP ERP--&gt;ISSSP--&gt;賽普--&gt;天貓，京東，蘇寧
5. 資產負債表，會計報表包括B2C



1. value chain價值鏈
2. C/4 HANA
3. SAP Hybris 一個獨立產品，有5個Module
4. ADP in SD/MM/PP
5. SE 16N/SE 16E/SE 16H
6. S/4 HANA QC
7. IDES \(RFC i.doc/Web Service\)

10/29 kick-off meeting

1. FI/CO/SD/MM
2. 第一階段:
   1. 收集文件
   2. 做PPT
   3. 教User，並收集需求
3. MES 工廠工單
4. 顧問給流程
5. User需求一律收集後回報給PM
6. 軟工
   1. DEV\(開發環境\)
   2. QAS\(從DEV copy，給user測試\)
   3. PRD\(正式產品\)

SAP Overview

1. FI/CO:財務會計
2. Company code : 四碼
3. 會計科目表:四碼
4. 作帳幣別
5. ACDOCA:三個記帳幣別，交易幣別不限數量
6. 費用分擔 --&gt; 多個Company\(法人\) --&gt;一個Area 即可\(Controlling Area，以集團為單位\)
7. 費用代碼 in Cost Center\(費用歸屬單位\)
8. Profit Center\(利潤中心\)--BU\(Business Unit\)別/產品別/功能別/區域別
9. SUT/法人 利潤中心/成本中心
10. SUT AS-IS/charge account

10/30 SD/MM Overview

1. 採購管理/銷售管理
2. Site 店別/Storage Location 倉別/採購組織\(集中\(多個site一個採購組織\)，分開\(一個site一個採購組織\)\)
3. B2B工廠直送+B2B2C
4. B2C工廠+DC\(準時達，天貓物流\(菜鳥\)\)+C
5. STO單\(採購單\)
6. 銷售組織/配銷通路\(產品部門\)/Sale Area
7. 商品群組\(MCH約3~4層\)
8. 商品分類
9. 銷貨--&gt;Delivery--&gt;請款--&gt;會計文件
10. GTIN\(條碼\)
11. Material Type:原料/成品/半成品
12. 供應商/客戶各一個table做維護
13. 供應商決定交易幣別
14. 貿易條件+付款條件\(國際貿易條款所定義\)
15. BP\(Business Partner\):個人，組織，群組
16. 物料編號\(商品現有的編號\)
17. NLAG:管量不管錢

10/31

{% file src="../.gitbook/assets/mm-note.docx" %}

1. 用戶不了解Best Practice
   1. SAP標準流程介紹
   2. 接口開發
2. 蘇寧主檔僅一個
3. 國美/蘇寧/代理商--各三個利潤中心
4. 應收帳款/付款人/送貨地/下單
5. 國美\(廣東/廣西\)\(下單\)--&gt;門店--&gt;三個倉別\(不同倉不同組織代碼不同\)
6. 客戶By商品分類
   1. 不同銷售組織追蹤不同商品&客戶
   2. 銷售分析表
   3. 銷售群組針對客戶做分類
7. DC倉\(物流合作的接口\)\(**SAP 倉管必須與準時達的倉儲做同步**\)
8. 銷售訂單:訂單可以先成立，出貨時的出貨單的地址可以後來補上
9. \(B2B\) 80%會工廠直出
   1. 準時達:16個 site
   2. 菜鳥:33個site--&gt;天貓\(B2C\)
10. 準時達倉別\(良/不良/正常/樣品\)
    1. 哪個倉庫的商品可以販售要再做確認
11. 採購組織:
    1. 商品組織
    2. 事務組織
12. 黑電/白電分兩個BU
13. 贈品/耗材...對應到商品群組該如何分類需再做確認
14. 商品定價的變動需要再做確認\(可能需要客製\)
15. 折讓\(紅沖\)--客戶開訂單的時候直接做折扣\(Debit/Credit Note\)
16. 配銷通路\(B2B/B2C/工廠直出\)
17. 銷售群組\(天貓/京東\)

IMG\(設定參數\)\(implementation guide\)   T-code :spro

11/5

1. 11/23前binary導入完成\(先to-be在as-is\)
2. 目前已經開始進行設定，向user要來的資料會設定進去，但是其他的之後再補
3. 與user的開會:
   1. 確認主檔資料
   2. 需求確認
      1. 根據Best Practice\(向顧問確認教育訓練的項目\)
      2. "因為之後會做教育訓練"，所以先確認SAP標準流程對應到User端是如何定義\(名稱\)
   3. 教育訓練Schedule\(根據Daily Plan的日期\)
4. 跟user先訂開會時間
5. 根據影片列出操作步驟



{% hint style="info" %}


\(TO-BE\)

步驟1:IMG 設定基本參數

步驟2:基本流程\(61個\)

步驟3:每個流程又分別定義不同階段\(對應到不同component\)

步驟4:每個component有不同的工作流程

\(AS-IS\)

步驟5:事務流程表\(系統+人工\)

步驟6:整理出各個流程的T-code文件
{% endhint %}



