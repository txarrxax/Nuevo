<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_13" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="XLXN_36" />
        <signal name="XLXN_40" />
        <signal name="XLXN_41" />
        <signal name="XLXN_42" />
        <signal name="XLXN_43" />
        <signal name="XLXN_45" />
        <signal name="XLXN_48" />
        <signal name="XLXN_50" />
        <signal name="XLXN_52" />
        <signal name="XLXN_54" />
        <signal name="XLXN_56" />
        <signal name="XLXN_58" />
        <signal name="XLXN_77" />
        <signal name="XLXN_87" />
        <signal name="XLXN_90" />
        <signal name="XLXN_93" />
        <signal name="XLXN_96" />
        <signal name="XLXN_98" />
        <signal name="XLXN_99" />
        <signal name="XLXN_100" />
        <signal name="A" />
        <signal name="XLXN_102" />
        <signal name="B" />
        <signal name="XLXN_104" />
        <signal name="Q1" />
        <signal name="XLXN_106" />
        <signal name="Q0" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <signal name="D0" />
        <signal name="D1" />
        <signal name="XLXN_125" />
        <signal name="XLXN_126" />
        <signal name="XLXN_127" />
        <signal name="XLXN_128" />
        <signal name="XLXN_129" />
        <signal name="O2" />
        <signal name="O0" />
        <signal name="O1" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="Q1" />
        <port polarity="Input" name="Q0" />
        <port polarity="Output" name="D0" />
        <port polarity="Output" name="D1" />
        <port polarity="Output" name="O2" />
        <port polarity="Output" name="O0" />
        <port polarity="Output" name="O1" />
        <blockdef name="and2b1">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-48" y2="-144" x1="64" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="40" y1="-64" y2="-64" x1="0" />
            <circle r="12" cx="52" cy="-64" />
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
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
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
        <blockdef name="buf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="0" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-64" x1="128" />
            <line x2="64" y1="-64" y2="0" x1="64" />
        </blockdef>
        <blockdef name="and3b1">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="40" y1="-64" y2="-64" x1="0" />
            <circle r="12" cx="52" cy="-64" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
        </blockdef>
        <blockdef name="and3b2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="40" y1="-64" y2="-64" x1="0" />
            <circle r="12" cx="52" cy="-64" />
            <line x2="40" y1="-128" y2="-128" x1="0" />
            <circle r="12" cx="52" cy="-128" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
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
        <block symbolname="and2b1" name="XLXI_1">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="Q1" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="Q1" name="I1" />
            <blockpin signalname="XLXN_9" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_3">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="Q0" name="I2" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_4">
            <blockpin signalname="XLXN_8" name="I0" />
            <blockpin signalname="XLXN_9" name="I1" />
            <blockpin signalname="XLXN_10" name="I2" />
            <blockpin signalname="D1" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="Q0" name="I1" />
            <blockpin signalname="XLXN_26" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="Q1" name="I1" />
            <blockpin signalname="XLXN_27" name="O" />
        </block>
        <block symbolname="and3b1" name="XLXI_8">
            <blockpin signalname="Q0" name="I0" />
            <blockpin signalname="Q1" name="I1" />
            <blockpin signalname="B" name="I2" />
            <blockpin signalname="XLXN_28" name="O" />
        </block>
        <block symbolname="and3b2" name="XLXI_9">
            <blockpin signalname="Q1" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="A" name="I2" />
            <blockpin signalname="XLXN_29" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_10">
            <blockpin signalname="XLXN_29" name="I0" />
            <blockpin signalname="XLXN_28" name="I1" />
            <blockpin signalname="XLXN_27" name="I2" />
            <blockpin signalname="XLXN_26" name="I3" />
            <blockpin signalname="D0" name="O" />
        </block>
        <block symbolname="and2b1" name="XLXI_67">
            <blockpin signalname="Q0" name="I0" />
            <blockpin signalname="Q1" name="I1" />
            <blockpin signalname="O2" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_68">
            <blockpin signalname="Q0" name="I0" />
            <blockpin signalname="Q1" name="I1" />
            <blockpin signalname="O0" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_69">
            <blockpin signalname="Q1" name="I" />
            <blockpin signalname="O1" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="A">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="320" y="992" type="branch" />
            <wire x2="320" y1="992" y2="992" x1="304" />
            <wire x2="384" y1="992" y2="992" x1="320" />
            <wire x2="384" y1="992" y2="1024" x1="384" />
            <wire x2="544" y1="1024" y2="1024" x1="384" />
            <wire x2="384" y1="1024" y2="1312" x1="384" />
            <wire x2="544" y1="1312" y2="1312" x1="384" />
            <wire x2="544" y1="432" y2="432" x1="384" />
            <wire x2="384" y1="432" y2="688" x1="384" />
            <wire x2="544" y1="688" y2="688" x1="384" />
            <wire x2="384" y1="688" y2="880" x1="384" />
            <wire x2="384" y1="880" y2="992" x1="384" />
            <wire x2="544" y1="880" y2="880" x1="384" />
        </branch>
        <branch name="B">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="320" y="1072" type="branch" />
            <wire x2="320" y1="1072" y2="1072" x1="304" />
            <wire x2="416" y1="1072" y2="1072" x1="320" />
            <wire x2="416" y1="1072" y2="1120" x1="416" />
            <wire x2="544" y1="1120" y2="1120" x1="416" />
            <wire x2="416" y1="1120" y2="1376" x1="416" />
            <wire x2="544" y1="1376" y2="1376" x1="416" />
            <wire x2="416" y1="560" y2="752" x1="416" />
            <wire x2="416" y1="752" y2="1072" x1="416" />
            <wire x2="544" y1="752" y2="752" x1="416" />
            <wire x2="544" y1="560" y2="560" x1="416" />
        </branch>
        <branch name="Q1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="320" y="1152" type="branch" />
            <wire x2="320" y1="1152" y2="1152" x1="304" />
            <wire x2="448" y1="1152" y2="1152" x1="320" />
            <wire x2="448" y1="1152" y2="1184" x1="448" />
            <wire x2="544" y1="1184" y2="1184" x1="448" />
            <wire x2="448" y1="1184" y2="1440" x1="448" />
            <wire x2="544" y1="1440" y2="1440" x1="448" />
            <wire x2="448" y1="1440" y2="1536" x1="448" />
            <wire x2="544" y1="1536" y2="1536" x1="448" />
            <wire x2="448" y1="1536" y2="1680" x1="448" />
            <wire x2="560" y1="1680" y2="1680" x1="448" />
            <wire x2="448" y1="1680" y2="1856" x1="448" />
            <wire x2="560" y1="1856" y2="1856" x1="448" />
            <wire x2="448" y1="496" y2="624" x1="448" />
            <wire x2="544" y1="624" y2="624" x1="448" />
            <wire x2="448" y1="624" y2="1088" x1="448" />
            <wire x2="448" y1="1088" y2="1152" x1="448" />
            <wire x2="544" y1="1088" y2="1088" x1="448" />
            <wire x2="544" y1="496" y2="496" x1="448" />
        </branch>
        <branch name="Q0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="320" y="1232" type="branch" />
            <wire x2="320" y1="1232" y2="1232" x1="304" />
            <wire x2="480" y1="1232" y2="1232" x1="320" />
            <wire x2="480" y1="1232" y2="1248" x1="480" />
            <wire x2="544" y1="1248" y2="1248" x1="480" />
            <wire x2="480" y1="1248" y2="1600" x1="480" />
            <wire x2="544" y1="1600" y2="1600" x1="480" />
            <wire x2="480" y1="1600" y2="1744" x1="480" />
            <wire x2="560" y1="1744" y2="1744" x1="480" />
            <wire x2="544" y1="816" y2="816" x1="480" />
            <wire x2="480" y1="816" y2="944" x1="480" />
            <wire x2="480" y1="944" y2="1232" x1="480" />
            <wire x2="544" y1="944" y2="944" x1="480" />
        </branch>
        <instance x="544" y="368" name="XLXI_1" orien="M180" />
        <instance x="544" y="496" name="XLXI_2" orien="M180" />
        <instance x="544" y="624" name="XLXI_3" orien="M180" />
        <instance x="912" y="464" name="XLXI_4" orien="M180" />
        <branch name="XLXN_8">
            <wire x2="912" y1="464" y2="464" x1="800" />
            <wire x2="912" y1="464" y2="528" x1="912" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="912" y1="592" y2="592" x1="800" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="912" y1="752" y2="752" x1="800" />
            <wire x2="912" y1="656" y2="752" x1="912" />
        </branch>
        <instance x="544" y="816" name="XLXI_6" orien="M180" />
        <instance x="544" y="960" name="XLXI_7" orien="M180" />
        <instance x="544" y="1312" name="XLXI_8" orien="R0" />
        <instance x="544" y="1504" name="XLXI_9" orien="R0" />
        <instance x="864" y="1280" name="XLXI_10" orien="R0" />
        <branch name="XLXN_26">
            <wire x2="864" y1="912" y2="912" x1="800" />
            <wire x2="864" y1="912" y2="1024" x1="864" />
        </branch>
        <branch name="XLXN_27">
            <wire x2="832" y1="1056" y2="1056" x1="800" />
            <wire x2="832" y1="1056" y2="1088" x1="832" />
            <wire x2="864" y1="1088" y2="1088" x1="832" />
        </branch>
        <branch name="XLXN_28">
            <wire x2="832" y1="1184" y2="1184" x1="800" />
            <wire x2="832" y1="1152" y2="1184" x1="832" />
            <wire x2="864" y1="1152" y2="1152" x1="832" />
        </branch>
        <branch name="XLXN_29">
            <wire x2="864" y1="1376" y2="1376" x1="800" />
            <wire x2="864" y1="1216" y2="1376" x1="864" />
        </branch>
        <branch name="D0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1136" y="1120" type="branch" />
            <wire x2="1136" y1="1120" y2="1120" x1="1120" />
            <wire x2="1152" y1="1120" y2="1120" x1="1136" />
        </branch>
        <iomarker fontsize="28" x="304" y="992" name="A" orien="R180" />
        <iomarker fontsize="28" x="304" y="1072" name="B" orien="R180" />
        <iomarker fontsize="28" x="304" y="1152" name="Q1" orien="R180" />
        <iomarker fontsize="28" x="304" y="1232" name="Q0" orien="R180" />
        <iomarker fontsize="28" x="1344" y="592" name="D1" orien="R0" />
        <iomarker fontsize="28" x="1152" y="1120" name="D0" orien="R0" />
        <branch name="D1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1312" y="592" type="branch" />
            <wire x2="1312" y1="592" y2="592" x1="1168" />
            <wire x2="1344" y1="592" y2="592" x1="1312" />
        </branch>
        <instance x="544" y="1664" name="XLXI_67" orien="R0" />
        <instance x="560" y="1808" name="XLXI_68" orien="R0" />
        <instance x="560" y="1888" name="XLXI_69" orien="R0" />
        <branch name="O2">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="816" y="1568" type="branch" />
            <wire x2="816" y1="1568" y2="1568" x1="800" />
            <wire x2="832" y1="1568" y2="1568" x1="816" />
        </branch>
        <iomarker fontsize="28" x="832" y="1568" name="O2" orien="R0" />
        <branch name="O0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1712" type="branch" />
            <wire x2="832" y1="1712" y2="1712" x1="816" />
            <wire x2="848" y1="1712" y2="1712" x1="832" />
        </branch>
        <iomarker fontsize="28" x="848" y="1712" name="O0" orien="R0" />
        <branch name="O1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="800" y="1856" type="branch" />
            <wire x2="800" y1="1856" y2="1856" x1="784" />
            <wire x2="816" y1="1856" y2="1856" x1="800" />
        </branch>
        <iomarker fontsize="28" x="816" y="1856" name="O1" orien="R0" />
    </sheet>
</drawing>