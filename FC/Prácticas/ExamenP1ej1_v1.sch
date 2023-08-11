<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="A" />
        <signal name="B" />
        <signal name="C" />
        <signal name="D" />
        <signal name="Z" />
        <signal name="XLXN_10" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="D" />
        <port polarity="Output" name="Z" />
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="or2" name="XLXI_1">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_2">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_3" name="I2" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_2" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="Z" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="A" name="I" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="992" y="1344" name="XLXI_1" orien="R0" />
        <instance x="992" y="1616" name="XLXI_2" orien="R0" />
        <instance x="1440" y="1472" name="XLXI_3" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1344" y1="1248" y2="1248" x1="1248" />
            <wire x2="1344" y1="1248" y2="1344" x1="1344" />
            <wire x2="1440" y1="1344" y2="1344" x1="1344" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1344" y1="1488" y2="1488" x1="1248" />
            <wire x2="1344" y1="1408" y2="1488" x1="1344" />
            <wire x2="1440" y1="1408" y2="1408" x1="1344" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="992" y1="1424" y2="1424" x1="960" />
        </branch>
        <instance x="736" y="1456" name="XLXI_4" orien="R0" />
        <branch name="A">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="640" y="1216" type="branch" />
            <wire x2="560" y1="1216" y2="1216" x1="480" />
            <wire x2="640" y1="1216" y2="1216" x1="560" />
            <wire x2="992" y1="1216" y2="1216" x1="640" />
            <wire x2="560" y1="1216" y2="1424" x1="560" />
            <wire x2="736" y1="1424" y2="1424" x1="560" />
        </branch>
        <branch name="D">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="608" y="1280" type="branch" />
            <wire x2="608" y1="1280" y2="1280" x1="480" />
            <wire x2="992" y1="1280" y2="1280" x1="608" />
        </branch>
        <branch name="B">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="576" y="1488" type="branch" />
            <wire x2="576" y1="1488" y2="1488" x1="480" />
            <wire x2="992" y1="1488" y2="1488" x1="576" />
        </branch>
        <branch name="C">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="800" y="1552" type="branch" />
            <wire x2="800" y1="1552" y2="1552" x1="480" />
            <wire x2="992" y1="1552" y2="1552" x1="800" />
        </branch>
        <iomarker fontsize="28" x="480" y="1216" name="A" orien="R180" />
        <iomarker fontsize="28" x="480" y="1280" name="D" orien="R180" />
        <iomarker fontsize="28" x="480" y="1488" name="B" orien="R180" />
        <iomarker fontsize="28" x="480" y="1552" name="C" orien="R180" />
        <branch name="Z">
            <wire x2="1728" y1="1376" y2="1376" x1="1696" />
        </branch>
        <iomarker fontsize="28" x="1728" y="1376" name="Z" orien="R0" />
    </sheet>
</drawing>