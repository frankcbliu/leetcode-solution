<p>给你两个字符串 <code>s</code><strong> </strong>和 <code>t</code> ，统计并返回在 <code>s</code> 的 <strong>子序列</strong> 中 <code>t</code> 出现的个数。</p>

<p>题目数据保证答案符合 32 位带符号整数范围。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>s = "rabbbit", t = "rabbit"<span><code>
<strong>输出</strong></code></span><strong>：</strong><span><code>3
</code></span><strong>解释：</strong>
如下所示, 有 3 种可以从 s 中得到 <span><code>"rabbit" 的方案</code></span>。
<span><code><strong><u>rabb</u></strong>b<strong><u>it</u></strong></code></span>
<span><code><strong><u>ra</u></strong>b<strong><u>bbit</u></strong></code></span>
<span><code><strong><u>rab</u></strong>b<strong><u>bit</u></strong></code></span></pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>s = "babgbag", t = "bag"
<span><code><strong>输出</strong></code></span><strong>：</strong><span><code>5
</code></span><strong>解释：</strong>
如下所示, 有 5 种可以从 s 中得到 <span><code>"bag" 的方案</code></span>。 
<span><code><strong><u>ba</u></strong>b<u><strong>g</strong></u>bag</code></span>
<span><code><strong><u>ba</u></strong>bgba<strong><u>g</u></strong></code></span>
<span><code><u><strong>b</strong></u>abgb<strong><u>ag</u></strong></code></span>
<span><code>ba<u><strong>b</strong></u>gb<u><strong>ag</strong></u></code></span>
<span><code>babg<strong><u>bag</u></strong></code></span>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>1 &lt;= s.length, t.length &lt;= 1000</code></li> 
 <li><code>s</code> 和 <code>t</code> 由英文字母组成</li> 
</ul>

<div><div>Related Topics</div><div><li>字符串</li><li>动态规划</li></div></div><br><div><li>👍 1082</li><li>👎 0</li></div>