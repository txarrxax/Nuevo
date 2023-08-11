<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="CLK" />
        <signal name="INIT" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_8" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_15" />
        <signal name="SIG_DIV" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <signal name="XLXN_30" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_36" />
        <port polarity="Input" name="CLK" />
        <port polarity="Input" name="INIT" />
        <port polarity="Output" name="SIG_DIV" />
        <blockdef name="cd4cle">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-576" y2="-576" x1="0" />
            <line x2="64" y1="-512" y2="-512" x1="0" />
            <line x2="64" y1="-448" y2="-448" x1="0" />
            <line x2="64" y1="-384" y2="-384" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-576" y2="-576" x1="384" />
            <line x2="320" y1="-512" y2="-512" x1="384" />
            <line x2="320" y1="-448" y2="-448" x1="384" />
            <line x2="320" y1="-384" y2="-384" x1="384" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <rect width="256" x="64" y="-640" height="576" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="and4b3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="40" y1="-64" y2="-64" x1="0" />
            <circle r="12" cx="52" cy="-64" />
            <line x2="40" y1="-128" y2="-128" x1="0" />
            <circle r="12" cx="52" cy="-128" />
            <line x2="40" y1="-192" y2="-192" x1="0" />
            <circle r="12" cx="52" cy="-192" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <line x2="64" y1="-64" y2="-256" x1="64" />
            <line x2="64" y1="-112" y2="-112" x1="144" />
            <arc ex="144" ey="-208" sx="144" sy="-112" r="48" cx="144" cy="-160" />
            <line x2="144" y1="-208" y2="-208" x1="64" />
        </blockdef>
        <blockdef name="and4b2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="40" y1="-64" y2="-64" x1="0" />
            <circle r="12" cx="52" cy="-64" />
            <line x2="40" y1="-128" y2="-128" x1="0" />
            <circle r="12" cx="52" cy="-128" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <line x2="144" y1="-208" y2="-208" x1="64" />
            <arc ex="144" ey="-208" sx="144" sy="-112" r="48" cx="144" cy="-160" />
            <line x2="64" y1="-64" y2="-256" x1="64" />
            <line x2="64" y1="-112" y2="-112" x1="144" />
        </blockdef>
        <block symbolname="cd4cle" name="XLXI_1">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="XLXN_8" name="CE" />
            <blockpin signalname="INIT" name="CLR" />
            <blockpin signalname="XLXN_28" name="D0" />
            <blockpin signalname="XLXN_28" name="D1" />
            <blockpin signalname="XLXN_28" name="D2" />
            <blockpin signalname="XLXN_28" name="D3" />
            <blockpin signalname="SIG_DIV" name="L" />
            <blockpin name="CEO" />
            <blockpin signalname="XLXN_6" name="Q0" />
            <blockpin signalname="XLXN_5" name="Q1" />
            <blockpin signalname="XLXN_4" name="Q2" />
            <blockpin signalname="XLXN_3" name="Q3" />
            <blockpin name="TC" />
        </block>
        <block symbolname="vcc" name="XLXI_2">
            <blockpin signalname="XLXN_8" name="P" />
        </block>
        <block symbolname="gnd" name="XLXI_4">
            <blockpin signalname="XLXN_28" name="G" />
        </block>
        <block symbolname="cd4cle" name="XLXI_5">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="XLXN_8" name="CE" />
            <blockpin signalname="INIT" name="CLR" />
            <blockpin signalname="XLXN_28" name="D0" />
            <blockpin signalname="XLXN_28" name="D1" />
            <blockpin signalname="XLXN_28" name="D2" />
            <blockpin signalname="XLXN_28" name="D3" />
            <blockpin signalname="XLXN_36" name="L" />
            <blockpin name="CEO" />
            <blockpin signalname="XLXN_22" name="Q0" />
            <blockpin signalname="XLXN_23" name="Q1" />
            <blockpin signalname="XLXN_24" name="Q2" />
            <blockpin signalname="XLXN_25" name="Q3" />
            <blockpin name="TC" />
        </block>
        <block symbolname="and4b3" name="XLXI_9">
            <blockpin signalname="XLXN_22" name="I0" />
            <blockpin signalname="XLXN_25" name="I1" />
            <blockpin signalname="XLXN_23" name="I2" />
            <blockpin signalname="XLXN_24" name="I3" />
            <blockpin signalname="SIG_DIV" name="O" />
        </block>
        <block symbolname="and4b2" name="XLXI_12">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="XLXN_3" name="I1" />
            <blockpin signalname="XLXN_5" name="I2" />
            <blockpin signalname="XLXN_4" name="I3" />
            <blockpin signalname="XLXN_36" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="736" y="1856" name="XLXI_1" orien="R0" />
        <branch name="CLK">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="480" y="1728" type="branch" />
            <wire x2="480" y1="1728" y2="1728" x1="464" />
            <wire x2="528" y1="1728" y2="1728" x1="480" />
            <wire x2="736" y1="1728" y2="1728" x1="528" />
            <wire x2="528" y1="1728" y2="1888" x1="528" />
            <wire x2="1776" y1="1888" y2="1888" x1="528" />
            <wire x2="1824" y1="1728" y2="1728" x1="1776" />
            <wire x2="1776" y1="1728" y2="1888" x1="1776" />
        </branch>
        <branch name="INIT">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="512" y="1824" type="branch" />
            <wire x2="512" y1="1824" y2="1824" x1="464" />
            <wire x2="576" y1="1824" y2="1824" x1="512" />
            <wire x2="736" y1="1824" y2="1824" x1="576" />
            <wire x2="576" y1="1824" y2="1904" x1="576" />
            <wire x2="1824" y1="1904" y2="1904" x1="576" />
            <wire x2="1824" y1="1824" y2="1904" x1="1824" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1152" y1="1472" y2="1472" x1="1120" />
            <wire x2="1152" y1="1472" y2="1536" x1="1152" />
            <wire x2="1248" y1="1536" y2="1536" x1="1152" />
            <wire x2="1248" y1="1344" y2="1536" x1="1248" />
            <wire x2="1264" y1="1344" y2="1344" x1="1248" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="1184" y1="1408" y2="1408" x1="1120" />
            <wire x2="1184" y1="1408" y2="1472" x1="1184" />
            <wire x2="1264" y1="1472" y2="1472" x1="1184" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1200" y1="1344" y2="1344" x1="1120" />
            <wire x2="1200" y1="1344" y2="1408" x1="1200" />
            <wire x2="1264" y1="1408" y2="1408" x1="1200" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1264" y1="1280" y2="1280" x1="1120" />
        </branch>
        <instance x="288" y="1088" name="XLXI_2" orien="R0" />
        <branch name="XLXN_8">
            <wire x2="352" y1="1088" y2="1664" x1="352" />
            <wire x2="720" y1="1664" y2="1664" x1="352" />
            <wire x2="736" y1="1664" y2="1664" x1="720" />
            <wire x2="720" y1="1152" y2="1664" x1="720" />
            <wire x2="1168" y1="1152" y2="1152" x1="720" />
            <wire x2="1168" y1="1152" y2="1664" x1="1168" />
            <wire x2="1824" y1="1664" y2="1664" x1="1168" />
        </branch>
        <instance x="576" y="960" name="XLXI_4" orien="R180" />
        <instance x="1824" y="1856" name="XLXI_5" orien="R0" />
        <branch name="XLXN_22">
            <wire x2="2576" y1="1280" y2="1280" x1="2208" />
        </branch>
        <branch name="XLXN_23">
            <wire x2="2448" y1="1344" y2="1344" x1="2208" />
            <wire x2="2448" y1="1344" y2="1408" x1="2448" />
            <wire x2="2576" y1="1408" y2="1408" x1="2448" />
        </branch>
        <branch name="XLXN_24">
            <wire x2="2368" y1="1408" y2="1408" x1="2208" />
            <wire x2="2368" y1="1408" y2="1456" x1="2368" />
            <wire x2="2528" y1="1456" y2="1456" x1="2368" />
            <wire x2="2528" y1="1456" y2="1472" x1="2528" />
            <wire x2="2576" y1="1472" y2="1472" x1="2528" />
        </branch>
        <branch name="XLXN_25">
            <wire x2="2464" y1="1472" y2="1472" x1="2208" />
            <wire x2="2464" y1="1344" y2="1472" x1="2464" />
            <wire x2="2576" y1="1344" y2="1344" x1="2464" />
        </branch>
        <branch name="SIG_DIV">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2848" y="1376" type="branch" />
            <wire x2="736" y1="1600" y2="1600" x1="672" />
            <wire x2="672" y1="1600" y2="1872" x1="672" />
            <wire x2="2928" y1="1872" y2="1872" x1="672" />
            <wire x2="2848" y1="1376" y2="1376" x1="2832" />
            <wire x2="2928" y1="1376" y2="1376" x1="2848" />
            <wire x2="3088" y1="1376" y2="1376" x1="2928" />
            <wire x2="2928" y1="1376" y2="1872" x1="2928" />
        </branch>
        <iomarker fontsize="28" x="464" y="1728" name="CLK" orien="R180" />
        <iomarker fontsize="28" x="464" y="1824" name="INIT" orien="R180" />
        <iomarker fontsize="28" x="3088" y="1376" name="SIG_DIV" orien="R0" />
        <instance x="2576" y="1216" name="XLXI_9" orien="M180" />
        <branch name="XLXN_28">
            <wire x2="512" y1="1088" y2="1136" x1="512" />
            <wire x2="1696" y1="1136" y2="1136" x1="512" />
            <wire x2="1696" y1="1136" y2="1280" x1="1696" />
            <wire x2="1696" y1="1280" y2="1344" x1="1696" />
            <wire x2="1696" y1="1344" y2="1408" x1="1696" />
            <wire x2="1696" y1="1408" y2="1472" x1="1696" />
            <wire x2="1824" y1="1472" y2="1472" x1="1696" />
            <wire x2="1824" y1="1408" y2="1408" x1="1696" />
            <wire x2="1824" y1="1344" y2="1344" x1="1696" />
            <wire x2="1824" y1="1280" y2="1280" x1="1696" />
            <wire x2="512" y1="1136" y2="1280" x1="512" />
            <wire x2="736" y1="1280" y2="1280" x1="512" />
            <wire x2="512" y1="1280" y2="1344" x1="512" />
            <wire x2="736" y1="1344" y2="1344" x1="512" />
            <wire x2="512" y1="1344" y2="1408" x1="512" />
            <wire x2="736" y1="1408" y2="1408" x1="512" />
            <wire x2="512" y1="1408" y2="1472" x1="512" />
            <wire x2="736" y1="1472" y2="1472" x1="512" />
        </branch>
        <instance x="1264" y="1216" name="XLXI_12" orien="M180" />
        <branch name="XLXN_36">
            <wire x2="1664" y1="1376" y2="1376" x1="1520" />
            <wire x2="1664" y1="1376" y2="1600" x1="1664" />
            <wire x2="1824" y1="1600" y2="1600" x1="1664" />
        </branch>
    </sheet>
</drawing>