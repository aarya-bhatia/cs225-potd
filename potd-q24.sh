#!/bin/sh
# This script was generated using Makeself 2.3.0

ORIG_UMASK=`umask`
if test "n" = n; then
    umask 077
fi

CRCsum="2763356401"
MD5="5b63abb99bcda6c7324e807689f3b89f"
TMPROOT=${TMPDIR:=/tmp}
USER_PWD="$PWD"; export USER_PWD

label="Extracting potd-q24"
script="echo"
scriptargs="The initial files can be found in the newly created directory: potd-q24"
licensetxt=""
helpheader=''
targetdir="potd-q24"
filesizes="2503"
keep="y"
nooverwrite="n"
quiet="n"
nodiskspace="n"

print_cmd_arg=""
if type printf > /dev/null; then
    print_cmd="printf"
elif test -x /usr/ucb/echo; then
    print_cmd="/usr/ucb/echo"
else
    print_cmd="echo"
fi

unset CDPATH

MS_Printf()
{
    $print_cmd $print_cmd_arg "$1"
}

MS_PrintLicense()
{
  if test x"$licensetxt" != x; then
    echo "$licensetxt"
    while true
    do
      MS_Printf "Please type y to accept, n otherwise: "
      read yn
      if test x"$yn" = xn; then
        keep=n
	eval $finish; exit 1
        break;
      elif test x"$yn" = xy; then
        break;
      fi
    done
  fi
}

MS_diskspace()
{
	(
	if test -d /usr/xpg4/bin; then
		PATH=/usr/xpg4/bin:$PATH
	fi
	df -kP "$1" | tail -1 | awk '{ if ($4 ~ /%/) {print $3} else {print $4} }'
	)
}

MS_dd()
{
    blocks=`expr $3 / 1024`
    bytes=`expr $3 % 1024`
    dd if="$1" ibs=$2 skip=1 obs=1024 conv=sync 2> /dev/null | \
    { test $blocks -gt 0 && dd ibs=1024 obs=1024 count=$blocks ; \
      test $bytes  -gt 0 && dd ibs=1 obs=1024 count=$bytes ; } 2> /dev/null
}

MS_dd_Progress()
{
    if test x"$noprogress" = xy; then
        MS_dd $@
        return $?
    fi
    file="$1"
    offset=$2
    length=$3
    pos=0
    bsize=4194304
    while test $bsize -gt $length; do
        bsize=`expr $bsize / 4`
    done
    blocks=`expr $length / $bsize`
    bytes=`expr $length % $bsize`
    (
        dd ibs=$offset skip=1 2>/dev/null
        pos=`expr $pos \+ $bsize`
        MS_Printf "     0%% " 1>&2
        if test $blocks -gt 0; then
            while test $pos -le $length; do
                dd bs=$bsize count=1 2>/dev/null
                pcent=`expr $length / 100`
                pcent=`expr $pos / $pcent`
                if test $pcent -lt 100; then
                    MS_Printf "\b\b\b\b\b\b\b" 1>&2
                    if test $pcent -lt 10; then
                        MS_Printf "    $pcent%% " 1>&2
                    else
                        MS_Printf "   $pcent%% " 1>&2
                    fi
                fi
                pos=`expr $pos \+ $bsize`
            done
        fi
        if test $bytes -gt 0; then
            dd bs=$bytes count=1 2>/dev/null
        fi
        MS_Printf "\b\b\b\b\b\b\b" 1>&2
        MS_Printf " 100%%  " 1>&2
    ) < "$file"
}

MS_Help()
{
    cat << EOH >&2
${helpheader}Makeself version 2.3.0
 1) Getting help or info about $0 :
  $0 --help   Print this message
  $0 --info   Print embedded info : title, default target directory, embedded script ...
  $0 --lsm    Print embedded lsm entry (or no LSM)
  $0 --list   Print the list of files in the archive
  $0 --check  Checks integrity of the archive

 2) Running $0 :
  $0 [options] [--] [additional arguments to embedded script]
  with following options (in that order)
  --confirm             Ask before running embedded script
  --quiet		Do not print anything except error messages
  --noexec              Do not run embedded script
  --keep                Do not erase target directory after running
			the embedded script
  --noprogress          Do not show the progress during the decompression
  --nox11               Do not spawn an xterm
  --nochown             Do not give the extracted files to the current user
  --nodiskspace         Do not check for available disk space
  --target dir          Extract directly to a target directory
                        directory path can be either absolute or relative
  --tar arg1 [arg2 ...] Access the contents of the archive through the tar command
  --                    Following arguments will be passed to the embedded script
EOH
}

MS_Check()
{
    OLD_PATH="$PATH"
    PATH=${GUESS_MD5_PATH:-"$OLD_PATH:/bin:/usr/bin:/sbin:/usr/local/ssl/bin:/usr/local/bin:/opt/openssl/bin"}
	MD5_ARG=""
    MD5_PATH=`exec <&- 2>&-; which md5sum || command -v md5sum || type md5sum`
    test -x "$MD5_PATH" || MD5_PATH=`exec <&- 2>&-; which md5 || command -v md5 || type md5`
	test -x "$MD5_PATH" || MD5_PATH=`exec <&- 2>&-; which digest || command -v digest || type digest`
    PATH="$OLD_PATH"

    if test x"$quiet" = xn; then
		MS_Printf "Verifying archive integrity..."
    fi
    offset=`head -n 532 "$1" | wc -c | tr -d " "`
    verb=$2
    i=1
    for s in $filesizes
    do
		crc=`echo $CRCsum | cut -d" " -f$i`
		if test -x "$MD5_PATH"; then
			if test x"`basename $MD5_PATH`" = xdigest; then
				MD5_ARG="-a md5"
			fi
			md5=`echo $MD5 | cut -d" " -f$i`
			if test x"$md5" = x00000000000000000000000000000000; then
				test x"$verb" = xy && echo " $1 does not contain an embedded MD5 checksum." >&2
			else
				md5sum=`MS_dd_Progress "$1" $offset $s | eval "$MD5_PATH $MD5_ARG" | cut -b-32`;
				if test x"$md5sum" != x"$md5"; then
					echo "Error in MD5 checksums: $md5sum is different from $md5" >&2
					exit 2
				else
					test x"$verb" = xy && MS_Printf " MD5 checksums are OK." >&2
				fi
				crc="0000000000"; verb=n
			fi
		fi
		if test x"$crc" = x0000000000; then
			test x"$verb" = xy && echo " $1 does not contain a CRC checksum." >&2
		else
			sum1=`MS_dd_Progress "$1" $offset $s | CMD_ENV=xpg4 cksum | awk '{print $1}'`
			if test x"$sum1" = x"$crc"; then
				test x"$verb" = xy && MS_Printf " CRC checksums are OK." >&2
			else
				echo "Error in checksums: $sum1 is different from $crc" >&2
				exit 2;
			fi
		fi
		i=`expr $i + 1`
		offset=`expr $offset + $s`
    done
    if test x"$quiet" = xn; then
		echo " All good."
    fi
}

UnTAR()
{
    if test x"$quiet" = xn; then
		tar $1vf - 2>&1 || { echo Extraction failed. > /dev/tty; kill -15 $$; }
    else

		tar $1f - 2>&1 || { echo Extraction failed. > /dev/tty; kill -15 $$; }
    fi
}

finish=true
xterm_loop=
noprogress=n
nox11=n
copy=none
ownership=y
verbose=n

initargs="$@"

while true
do
    case "$1" in
    -h | --help)
	MS_Help
	exit 0
	;;
    -q | --quiet)
	quiet=y
	noprogress=y
	shift
	;;
    --info)
	echo Identification: "$label"
	echo Target directory: "$targetdir"
	echo Uncompressed size: 32 KB
	echo Compression: gzip
	echo Date of packaging: Tue Oct  6 23:33:16 CDT 2020
	echo Built with Makeself version 2.3.0 on 
	echo Build command was: "./makeself/makeself.sh \\
    \"--notemp\" \\
    \"../../questions/potd3_024_linked_list_defragmentation/potd-q24\" \\
    \"../../questions/potd3_024_linked_list_defragmentation/clientFilesQuestion/potd-q24.sh\" \\
    \"Extracting potd-q24\" \\
    \"echo\" \\
    \"The initial files can be found in the newly created directory: potd-q24\""
	if test x"$script" != x; then
	    echo Script run after extraction:
	    echo "    " $script $scriptargs
	fi
	if test x"" = xcopy; then
		echo "Archive will copy itself to a temporary location"
	fi
	if test x"n" = xy; then
		echo "Root permissions required for extraction"
	fi
	if test x"y" = xy; then
	    echo "directory $targetdir is permanent"
	else
	    echo "$targetdir will be removed after extraction"
	fi
	exit 0
	;;
    --dumpconf)
	echo LABEL=\"$label\"
	echo SCRIPT=\"$script\"
	echo SCRIPTARGS=\"$scriptargs\"
	echo archdirname=\"potd-q24\"
	echo KEEP=y
	echo NOOVERWRITE=n
	echo COMPRESS=gzip
	echo filesizes=\"$filesizes\"
	echo CRCsum=\"$CRCsum\"
	echo MD5sum=\"$MD5\"
	echo OLDUSIZE=32
	echo OLDSKIP=533
	exit 0
	;;
    --lsm)
cat << EOLSM
No LSM.
EOLSM
	exit 0
	;;
    --list)
	echo Target directory: $targetdir
	offset=`head -n 532 "$0" | wc -c | tr -d " "`
	for s in $filesizes
	do
	    MS_dd "$0" $offset $s | eval "gzip -cd" | UnTAR t
	    offset=`expr $offset + $s`
	done
	exit 0
	;;
	--tar)
	offset=`head -n 532 "$0" | wc -c | tr -d " "`
	arg1="$2"
    if ! shift 2; then MS_Help; exit 1; fi
	for s in $filesizes
	do
	    MS_dd "$0" $offset $s | eval "gzip -cd" | tar "$arg1" - "$@"
	    offset=`expr $offset + $s`
	done
	exit 0
	;;
    --check)
	MS_Check "$0" y
	exit 0
	;;
    --confirm)
	verbose=y
	shift
	;;
	--noexec)
	script=""
	shift
	;;
    --keep)
	keep=y
	shift
	;;
    --target)
	keep=y
	targetdir=${2:-.}
    if ! shift 2; then MS_Help; exit 1; fi
	;;
    --noprogress)
	noprogress=y
	shift
	;;
    --nox11)
	nox11=y
	shift
	;;
    --nochown)
	ownership=n
	shift
	;;
    --nodiskspace)
	nodiskspace=y
	shift
	;;
    --xwin)
	if test "n" = n; then
		finish="echo Press Return to close this window...; read junk"
	fi
	xterm_loop=1
	shift
	;;
    --phase2)
	copy=phase2
	shift
	;;
    --)
	shift
	break ;;
    -*)
	echo Unrecognized flag : "$1" >&2
	MS_Help
	exit 1
	;;
    *)
	break ;;
    esac
done

if test x"$quiet" = xy -a x"$verbose" = xy; then
	echo Cannot be verbose and quiet at the same time. >&2
	exit 1
fi

if test x"n" = xy -a `id -u` -ne 0; then
	echo "Administrative privileges required for this archive (use su or sudo)" >&2
	exit 1	
fi

if test x"$copy" \!= xphase2; then
    MS_PrintLicense
fi

case "$copy" in
copy)
    tmpdir=$TMPROOT/makeself.$RANDOM.`date +"%y%m%d%H%M%S"`.$$
    mkdir "$tmpdir" || {
	echo "Could not create temporary directory $tmpdir" >&2
	exit 1
    }
    SCRIPT_COPY="$tmpdir/makeself"
    echo "Copying to a temporary location..." >&2
    cp "$0" "$SCRIPT_COPY"
    chmod +x "$SCRIPT_COPY"
    cd "$TMPROOT"
    exec "$SCRIPT_COPY" --phase2 -- $initargs
    ;;
phase2)
    finish="$finish ; rm -rf `dirname $0`"
    ;;
esac

if test x"$nox11" = xn; then
    if tty -s; then                 # Do we have a terminal?
	:
    else
        if test x"$DISPLAY" != x -a x"$xterm_loop" = x; then  # No, but do we have X?
            if xset q > /dev/null 2>&1; then # Check for valid DISPLAY variable
                GUESS_XTERMS="xterm gnome-terminal rxvt dtterm eterm Eterm xfce4-terminal lxterminal kvt konsole aterm terminology"
                for a in $GUESS_XTERMS; do
                    if type $a >/dev/null 2>&1; then
                        XTERM=$a
                        break
                    fi
                done
                chmod a+x $0 || echo Please add execution rights on $0
                if test `echo "$0" | cut -c1` = "/"; then # Spawn a terminal!
                    exec $XTERM -title "$label" -e "$0" --xwin "$initargs"
                else
                    exec $XTERM -title "$label" -e "./$0" --xwin "$initargs"
                fi
            fi
        fi
    fi
fi

if test x"$targetdir" = x.; then
    tmpdir="."
else
    if test x"$keep" = xy; then
	if test x"$nooverwrite" = xy && test -d "$targetdir"; then
            echo "Target directory $targetdir already exists, aborting." >&2
            exit 1
	fi
	if test x"$quiet" = xn; then
	    echo "Creating directory $targetdir" >&2
	fi
	tmpdir="$targetdir"
	dashp="-p"
    else
	tmpdir="$TMPROOT/selfgz$$$RANDOM"
	dashp=""
    fi
    mkdir $dashp $tmpdir || {
	echo 'Cannot create target directory' $tmpdir >&2
	echo 'You should try option --target dir' >&2
	eval $finish
	exit 1
    }
fi

location="`pwd`"
if test x"$SETUP_NOCHECK" != x1; then
    MS_Check "$0"
fi
offset=`head -n 532 "$0" | wc -c | tr -d " "`

if test x"$verbose" = xy; then
	MS_Printf "About to extract 32 KB in $tmpdir ... Proceed ? [Y/n] "
	read yn
	if test x"$yn" = xn; then
		eval $finish; exit 1
	fi
fi

if test x"$quiet" = xn; then
	MS_Printf "Uncompressing $label"
fi
res=3
if test x"$keep" = xn; then
    trap 'echo Signal caught, cleaning up >&2; cd $TMPROOT; /bin/rm -rf $tmpdir; eval $finish; exit 15' 1 2 3 15
fi

if test x"$nodiskspace" = xn; then
    leftspace=`MS_diskspace $tmpdir`
    if test -n "$leftspace"; then
        if test "$leftspace" -lt 32; then
            echo
            echo "Not enough space left in "`dirname $tmpdir`" ($leftspace KB) to decompress $0 (32 KB)" >&2
            echo "Use --nodiskspace option to skip this check and proceed anyway" >&2
            if test x"$keep" = xn; then
                echo "Consider setting TMPDIR to a directory with more free space."
            fi
            eval $finish; exit 1
        fi
    fi
fi

for s in $filesizes
do
    if MS_dd_Progress "$0" $offset $s | eval "gzip -cd" | ( cd "$tmpdir"; umask $ORIG_UMASK ; UnTAR xp ) 1>/dev/null; then
		if test x"$ownership" = xy; then
			(PATH=/usr/xpg4/bin:$PATH; cd "$tmpdir"; chown -R `id -u` .;  chgrp -R `id -g` .)
		fi
    else
		echo >&2
		echo "Unable to decompress $0" >&2
		eval $finish; exit 1
    fi
    offset=`expr $offset + $s`
done
if test x"$quiet" = xn; then
	echo
fi

cd "$tmpdir"
res=0
if test x"$script" != x; then
    if test x"$verbose" = x"y"; then
		MS_Printf "OK to execute: $script $scriptargs $* ? [Y/n] "
		read yn
		if test x"$yn" = x -o x"$yn" = xy -o x"$yn" = xY; then
			eval "\"$script\" $scriptargs \"\$@\""; res=$?;
		fi
    else
		eval "\"$script\" $scriptargs \"\$@\""; res=$?
    fi
    if test "$res" -ne 0; then
		test x"$verbose" = xy && echo "The program '$script' returned an error code ($res)" >&2
    fi
fi
if test x"$keep" = xn; then
    cd $TMPROOT
    /bin/rm -rf $tmpdir
fi
eval $finish; exit $res
‹ E}_íksÛFÎ_Ëÿ‡›©%»’õ²•‘b÷Ü8Í\Ç±o.×inr¹M®¤­©¥†ÛiGÿı€}Ë‡$¿dßƒø Ç.`¢¹·±vhôûûøİîï·Ìoín¿ÛïôÚ]o·:­îÙßxˆÃÈÙøÍÒp	ŞªùÿRhî½§S?øÚœ¬÷üzÏ·»@êï·¯fĞÙ ­êü×ßÎ{<µ‰ÏjYß2îx±KÉÖ™ïÒæd+yí„‘ë±‹#cèŠ:‘˜#qÄ<}=²,zÑ€“˜‡lÌ©K¦öÍ±ë4‡–åxviyäk_xÌX£µúPşe<"¶çùÑZÈ~§ÿŠ~Á<N_ø¾GF¥µd'[n£	\ùÌ%.¡œ”G	á?í1­)z)•+›yö…GkB³ úÙQX ´³CÆ4Ã)Å/§48½™ÄüRL™+h`bábøUCÕïŸŠŠ1îV•2\©(AsÑš	µ]àr>´Vùÿ;vEyÓ™ÍŞÿûıƒN.şwÛ€^ùÿSøâñú9`ú<óÃ( öô(36µ9›-Ë"C2>&õ9³J ®€–
rHZ7m4˜ßÛÙ±şJ£8à!‰&”pp…$0À*Kô˜·#â;N„ÄA+ÆhâÂGˆ³_NO‰ãÁ5©µ³gI—‘jnën¾Rƒˆ1À8Î5Ié×æQRÓ/zµt£dºqÄø/!5g!¾Şd˜ÌÍ“_éş	¥”…¹WŠ
n?´æEÅªğIü‘ü›W1è®ÑFnÕó9A¬¤.*ÃµVaiØ^ /©–k*£ªyeåµµ·GŞL¨s)¶EiğH2Š­hÂB¼À…ÁŠ´ğæ¾	öÑaF ÂÚŒ£±¦›4Äì°°&+®bšÛ_ó>"­2´üà»!8ËuQ|‰çVêy	?Úv0¦pÉRÓ[„}&— 8VKYøŒÊõã¬Lb»GÊƒÚFò#6[Ä–ÄFÔY@¯˜‡’·³…+æVépF«h$ü›|¼èë¹¨PÏ«N-K`n•ğ½"f[4Ú"`h÷Ö‰šR=z°y”­ôK¢Œ
&Ú7³ñ‰ò!½YIr”‰$ZÑ¹°›sñ\‡Ã©ÅËµÅ%fvX43#l¬†ITéPPCùJimö’Åæ¤bÌ¦V‘ÊcÕFZr?²=|ïvoÿ€’›í–ÅÑ;?«L±‘,Ê\ÙHÒ×*ö‹ç•Û2®¦CÈ«†b¦<­RO‚w4"åãh‚Şæ1~	ZôXO®YüqÆQíá’`Q'Z¤—¯ °¿"§.ƒ;[ˆ)'7¤“¿o¢TÈI?ñÏJìd*:õ`B4øz­‡ê„Ãÿİ]“s ÷‰}ÎQüÔùœaµL)¨=ÈéMªÁÕzÊ_XKº©Å=W§Yk4’! òñùSå(1Úˆ' …¸ûù)‹…/a¯¹à¿ÿf}ÕñcAıLO’’ìßÃáÄr!€¸ëköÍ;¿v¶B™@3³…ƒ\¡Aß" -©:HUDî` ÛGäõk²u¸¶oû|{X²üXs0€û“Àó8YøçW…Ki‚™¸¥ä¡nGéNÂ=Ø"2Nö–•ÅÔGH£ó¼Úvk»n^×zõÂ 3H`@šÜ÷²õgü±E`ü§€Ò­zN·õÇ,›†BçV¾ş#/ïë®ÿ/«ÿv:ûùúo§WÕ¡ş+ë²hFUV»`¶Âú½á0…Ú©é[)Ú0—¯›ÿõİg¸¬XYÁŞÿ`)aM…ßÛù·ß>(¼ÿéTşÿ¤õß´Ö»YòÒÇKÅ›Öfi1Ç1#FËÂŒiÓÊV£äİGUâ0ÕIQòîIˆEÁÜK”àœ"¸°0'Ä)¹¤™y#–ì·73ê`Á³8lŠ0³:íx™äIŸEJ#'u”¿-ñÖ.|¶ãÈÎ^"hrıiİô4q¼¥ÊÊ%yªú
ÚïÉ²·Şl6Óg¾X›V`EU·ù˜İÆr†¤‘)ßÖK±;wÂîŞ	»·;cÏaeFñƒiŸê‡^‡œì6¥¬• ¡¡‰¢Ï]i+QjoRõáÖ‡÷Rè’= ñ^¹'öæˆ%z×¾ùXj&,¸ƒÖ»÷Ôú½”úª\©¯ÖªÔ[iğ$yaz\¤·Ì[ıÿA­•„€ü“CU.0˜Ï7­ûäïíK
WúŒı?ín!ÿƒé*ÿ{xûñíÙñû·â%ã›Öù?Pš¾¸›Á—ÊøôÙ+â£¾ùøëÍÇ»»âïO§ÇïBüùĞÙİmİ†CcÒ8o‘Æ¯ğ(‡O¸üö¦uzb.>=)®Å=`É€¼¬)Në8”şÃä†¿yY;=©“—ÿ$øCĞª“†O^ş	—H‰D_w>ğ^ñK®@\)ö@Š¿Wëf µt+|¥ÂÉuß,[éxÔæ·¾iSÒ‘8S-÷¼ÿi!Ÿ±ş³ßÎûÿ~¿ºÿ=qÿÏ’?áƒÁŠ"ªºâKÊô•¦|14ft‰Õ(	©—·²%Œ7áºO¥*Õ¬·ÿw`Uı§İÊ×;íƒªÿ÷ÿ«ÿD0¹^UR±¤It	“#xm"×vHÂØq a{ØÆıÈúÈÆ\¾| Œ±«í7Ø‹GrÑ…ç;—!¹À&3?döØt"¢YÒXÚUü€şµÒFŠ$Pæ·0¹şîÇq°,‹Ô²ò@( {M‰cs)²Ul¸Â°j¾6J‹î÷iæB1E%"ùî;òtI,’eI?U¾ÍKl!{fî²EÅZÜQ¥[/Dóİƒ,Eó“x™¬šŸü`ó;X¸n~‚]œÍ4ôeÏ*fÇ‹ú.YHÆÏĞeEôÂ"JjòY'6w¥ÀˆësJ<í@öÄYaúÚ§.ü+ÚÄ'{wÚ_)q}t0X“±ÜÂ\,dI–Ñq2ïËÍkùcµ{.oÀ3?üO ´¤Ç–o¼R¨;?9‡›4“ê’–(© $j5œ°QDXZºÆ¾-Év¨6¿h4 ?-¸ª5÷šPo
ÅÜ³_–µ{QME_…¬Í­»¶Ş$
á¿ê€™š¢2“3hƒ«Ü¬‚
*¨ ‚
*¨ ‚
*¨ ‚
*¨ ‚
*¨ ‚
*¨à?	şÖÖÑ— P  