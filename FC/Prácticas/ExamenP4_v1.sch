<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="RST" />
        <signal name="XLXN_2" />
        <signal name="CLK" />
        <signal name="A" />
        <signal name="B" />
        <signal name="O2" />
        <signal name="O1" />
        <signal name="O0" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <port polarity="Input" name="RST" />
        <port polarity="Input" name="CLK" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Output" name="O2" />
        <port polarity="Output" name="O1" />
        <port polarity="Output" name="O0" />
        <blockdef name="fdc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
        </blockdef>
        <blockdef name="ctrl_v1">
            <timestamp>2022-12-14T10:33:57</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
        </blockdef>
        <block symbolname="fdc" name="XLXI_1">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="RST" name="CLR" />
            <blockpin signalname="XLXN_11" name="D" />
            <blockpin signalname="XLXN_9" name="Q" />
        </block>
        <block symbolname="fdc" name="XLXI_2">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="RST" name="CLR" />
            <blockpin signalname="XLXN_12" name="D" />
            <blockpin signalname="XLXN_10" name="Q" />
        </block>
        <block symbolname="ctrl_v1" name="XLXI_5">
            <blockpin signalname="A" name="A" />
            <blockpin signalname="B" name="B" />
            <blockpin signalname="XLXN_12" name="D0" />
            <blockpin signalname="XLXN_11" name="D1" />
            <blockpin signalname="O0" name="O0" />
            <blockpin signalname="O1" name="O1" />
            <blockpin signalname="O2" name="O2" />
            <blockpin signalname="XLXN_10" name="Q0" />
            <blockpin signalname="XLXN_9" name="Q1" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="784" y="1552" name="XLXI_1" orien="R0" />
        <instance x="1408" y="1552" name="XLXI_2" orien="R0" />
        <branch name="RST">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="560" y="1584" type="branch" />
            <wire x2="560" y1="1584" y2="1584" x1="544" />
            <wire x2="784" y1="1584" y2="1584" x1="560" />
            <wire x2="1408" y1="1584" y2="1584" x1="784" />
            <wire x2="784" y1="1520" y2="1584" x1="784" />
            <wire x2="1408" y1="1520" y2="1584" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="544" y="1584" name="RST" orien="R180" />
        <branch name="CLK">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="400" y="1536" type="branch" />
            <wire x2="400" y1="1536" y2="1536" x1="368" />
            <wire x2="432" y1="1536" y2="1536" x1="400" />
            <wire x2="1232" y1="1536" y2="1536" x1="432" />
            <wire x2="784" y1="1424" y2="1424" x1="432" />
            <wire x2="432" y1="1424" y2="1536" x1="432" />
            <wire x2="1232" y1="1424" y2="1536" x1="1232" />
            <wire x2="1408" y1="1424" y2="1424" x1="1232" />
        </branch>
        <iomarker fontsize="28" x="368" y="1536" name="CLK" orien="R180" />
        <branch name="A">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1072" y="704" type="branch" />
            <wire x2="1072" y1="704" y2="704" x1="1056" />
            <wire x2="1088" y1="704" y2="704" x1="1072" />
        </branch>
        <iomarker fontsize="28" x="1056" y="704" name="A" orien="R180" />
        <branch name="B">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1072" y="768" type="branch" />
            <wire x2="1072" y1="768" y2="768" x1="1056" />
            <wire x2="1088" y1="768" y2="768" x1="1072" />
        </branch>
        <branch name="O2">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1488" y="832" type="branch" />
            <wire x2="1488" y1="832" y2="832" x1="1472" />
            <wire x2="1504" y1="832" y2="832" x1="1488" />
        </branch>
        <iomarker fontsize="28" x="1504" y="832" name="O2" orien="R0" />
        <branch name="O1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1488" y="896" type="branch" />
            <wire x2="1488" y1="896" y2="896" x1="1472" />
            <wire x2="1504" y1="896" y2="896" x1="1488" />
        </branch>
        <iomarker fontsize="28" x="1504" y="896" name="O1" orien="R0" />
        <branch name="O0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1488" y="960" type="branch" />
            <wire x2="1488" y1="960" y2="960" x1="1472" />
            <wire x2="1504" y1="960" y2="960" x1="1488" />
        </branch>
        <iomarker fontsize="28" x="1504" y="960" name="O0" orien="R0" />
        <iomarker fontsize="28" x="1056" y="768" name="B" orien="R180" />
        <branch name="XLXN_9">
            <wire x2="1088" y1="832" y2="832" x1="1024" />
            <wire x2="1024" y1="832" y2="1072" x1="1024" />
            <wire x2="1232" y1="1072" y2="1072" x1="1024" />
            <wire x2="1232" y1="1072" y2="1296" x1="1232" />
            <wire x2="1232" y1="1296" y2="1296" x1="1168" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="1088" y1="896" y2="896" x1="1040" />
            <wire x2="1040" y1="896" y2="1056" x1="1040" />
            <wire x2="1856" y1="1056" y2="1056" x1="1040" />
            <wire x2="1856" y1="1056" y2="1296" x1="1856" />
            <wire x2="1856" y1="1296" y2="1296" x1="1792" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="1472" y1="592" y2="592" x1="720" />
            <wire x2="1472" y1="592" y2="704" x1="1472" />
            <wire x2="720" y1="592" y2="1296" x1="720" />
            <wire x2="784" y1="1296" y2="1296" x1="720" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="1344" y1="1152" y2="1296" x1="1344" />
            <wire x2="1408" y1="1296" y2="1296" x1="1344" />
            <wire x2="1680" y1="1152" y2="1152" x1="1344" />
            <wire x2="1680" y1="768" y2="768" x1="1472" />
            <wire x2="1680" y1="768" y2="1152" x1="1680" />
        </branch>
        <instance x="1088" y="992" name="XLXI_5" orien="R0">
        </instance>
    </sheet>
</drawing>